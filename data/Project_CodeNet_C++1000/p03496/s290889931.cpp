#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int l = INT_MAX, r = INT_MIN, li = -1, ri = -1;
    vector<pair<int, int>> ans;
    
    rep(i, N) {
        if (l > a[i]) {
            l = a[i];
            li = i;
        }
        
        if (r < a[i]) {
            r = a[i];
            ri = i;
        }
    }
    
    if ((l == 0) && (r == 0)) {
        printf("0\n");
        return 0;
    }
    
    if ((l < 0) && (r < 0)) {
        rrep(i, N - 1) {
            ans.emplace_back(i + 1, i);
        }
    }
    else if ((l > 0) && (r > 0)) {
        rep(i, N - 1) {
            ans.emplace_back(i, i + 1);
        }
    }
    else {
        if (abs(l) > abs(r)) {
            rep(i, N) {
                if (i == li) {
                    continue;
                }
                
                ans.emplace_back(li, i);
            }
            
            rrep(i, N - 1) {
                ans.emplace_back(i + 1, i);
            }
        }
        else {
            rep(i, N) {
                if (i == ri) {
                    continue;
                }
                
                ans.emplace_back(ri, i);
            }
            
            rep(i, N - 1) {
                ans.emplace_back(i, i + 1);
            }
        }
    }
    
    printf("%d\n", sz(ans));
    
    rep(i, sz(ans)) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
    
    return 0;
}