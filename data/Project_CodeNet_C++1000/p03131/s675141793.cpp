#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
int main(){
    ll k,a,b;
    cin >> k >> a >>b;
    ll ans = 0;
    if(b-a<=2||k<(a+1)){
        ans = k+1;
        cout << ans << endl;
        return 0;
    }
    k-=a-1;
    ans = a;
    ll num = k/2;
    ans += num*(b-a);
    if(k%2==1) ans++;
    cout << ans << endl;
    return 0;
}