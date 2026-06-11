#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int ans = 0;
    rep(l, k + 1){
        rep(r, k - l + 1){
            if(l + r > n)continue;
            priority_queue<int> q;
            int memo = 0;
            rep(i, l){
                memo += v[i];
                q.push(-v[i]);
            }
            rep(i,r){
                memo += v[n - i - 1];
                q.push(-v[n - i - 1]);
            }
            rep(i, k - l - r){
                if(!q.empty() && q.top() > 0){
                    memo += q.top();
                    q.pop();
                }else break;
            }
            ans = max(ans, memo);
        }
    }
    cout << ans << endl;
    return 0;
}
