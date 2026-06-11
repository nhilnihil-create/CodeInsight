#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=998244353;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n;
    cin >> n;
    for(ll a=1;a<=3500;a++){
        for(ll b=1;b<=3500;b++){
            ll t = n * a * b;
            ll t2 = 4 * a * b - n * (a + b);
            if(t2<=0) continue;
            if(t%t2!=0) continue;
            ll w = t/t2;
            cout << a << " " << b << " " << w << endl;
            return 0;
        }
    }
}