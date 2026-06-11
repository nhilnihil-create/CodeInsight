#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

ll gcd(ll x,ll y){
  if (y==0){
    return x;
  }
  return gcd(y,x%y);
}

int main(){
    ll T;
    cin >> T;
    rep(i,T){
        ll A,B,C,D;
        cin >> A >> B >> C >> D;
        if (A>=B&&B<=C){
            if (B>D){
                cout << "No" << endl;
            }
            else {
                cout << "Yes" << endl;
            }
            continue;
        }
        if (A<B){
            cout << "No" << endl;
            continue;
        }
        ll E=gcd(B,D);
        A%=B;
        ll F=(B-A-1)/E;
        if (A+F*E<=C&&D>=B){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}