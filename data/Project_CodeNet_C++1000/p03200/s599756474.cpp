#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    ll ans=0;
    string s;
    cin>>s;
    ll pos=0;
    rep(i,0,s.length()){
        ll cntb=0,cntw=0,tmp=0;
        if(s[i]=='B'){
            while(s[i]=='B'){tmp++;cntb++;i++;}
            while(s[i]=='W'){cntw++;i++;}
        }
        else continue;
        //cout<<pos<<" "<<cntb<<" "<<cntw<<endl;
        ans+=(cntb+pos)*cntw;
        pos+=tmp;
        i--;
    }
    cout<<ans;
}