#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    ll n;
    cin >> n;
    vector<ll>c(n-1),s(n-1),f(n-1);
    rep(i,n-1) {
        cin >> c[i] >> s[i] >> f[i];
    }
    rep(i,n-1) {
        ll ans = 0;
        ll arrived = s[i]+c[i];
        ans += arrived;
        for(int j = i+1;j<n-1;j++) {
            if(arrived<=s[j]) { //開通式前に到着
                ans = s[j]+c[j];
                arrived = s[j]+c[j];
            }
            else if(arrived%f[j]==0) {//開通式後に到着
                ans = arrived+c[j];
                arrived += c[j];
            }
            else {
                ll k = (arrived-s[j]+f[j])/f[j];
                ans = k*f[j]+s[j]+c[j];
                arrived = k*f[j]+s[j]+c[j];
            } 
        }
        cout << ans << endl;
    }
    cout << 0 << endl;
}