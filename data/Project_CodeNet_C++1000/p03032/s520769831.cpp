#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll>v(n);
    rep(i,n) {
        cin >> v[i];
    }
    
    ll ans = 0;
    for(ll a = 0;a<=n;a++) {
        for(ll b = 0;b<=n;b++) {
            vector<ll>val;
            ll tmp = 0;
            ll cnt = 0;
            if(a+b > n || a+b>k) continue;
            for(ll i = 0;i<a;i++) {
                val.push_back(v[i]);
                cnt++;
            }
            for(ll i = n-1;i>n-1-b;i--) {
                val.push_back(v[i]); 
                cnt++;
            }
            // cout << a << " " << b <<" ";
            cnt = k - cnt;
            // cout << a << " " << b <<" " << cnt << " ";
            sort(val.begin(),val.end());
            ll N = val.size();
            for(ll i = 0;i<N;i++) {
                if(cnt>0 && val[i]<0) {
                    cnt--;
                    continue;
                }
                tmp += val[i];
            }
            ans = max(ans,tmp);
            // cout << endl;
        }
        
    }
    cout << ans << endl;
}