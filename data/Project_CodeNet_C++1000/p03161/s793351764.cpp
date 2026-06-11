#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define reps(i, s, n) for(int i = (s); i < (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, s, n) for(int i = (n) - 1; i >= (s); i--)
#define INF ~(1 << 31)
#define INFL ~(1LL << 63)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n){
        cin >> h[i];
    }

    vector<int> ans(n);
    ans[0] = 0;
    reps(i, 1, n){
        int ansmin = INF;
        rep(j, min(i, k)){
            ansmin = min(ansmin, ans[i-j-1] + abs(h[i] - h[i-j-1]));
        }
        ans[i] = ansmin;
    }
    cout << ans[n-1] << endl;
}