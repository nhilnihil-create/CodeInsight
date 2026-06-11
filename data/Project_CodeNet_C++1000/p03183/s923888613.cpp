#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
 
struct block {
    int w, s, v;
};
 
bool cmp(const block &x, const block &y) {
    return x.w + x.s > y.w + y.s;
}
 
const int N = 2e4+10;
int memo[N];
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<block> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].w >> arr[i].s >> arr[i].v;
    }
    sort(arr.begin(), arr.end(), cmp);
    int res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < N; ++j) {
            /*
            if(j+1 < N) {
                memo[j] = max(memo[j], memo[j+1]);
            }
            */
            if(j-arr[i].w >= 0 && j-arr[i].w <= arr[i].s) {
                memo[j-arr[i].w] = max(memo[j-arr[i].w], arr[i].v + memo[j]);
                res = max(res, memo[j-arr[i].w]);
            }
        }
    }
    cout << res << '\n';
}
 
 
 
 
 