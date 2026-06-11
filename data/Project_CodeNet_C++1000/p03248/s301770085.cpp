#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
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

int main(){
    string s;
    cin >> s;
    int n=s.size();
    if (s[0]=='0'||s[n-1]=='1'){
        cout << -1 << endl;
        return 0;
    }
    rep(i,n-2){
        if (s[i]!=s[n-i-2]){
            cout << -1 << endl;
            return 0;
        }
    }
    int base=1;
    rep(i,n-1){
        cout << base << ' ' << i+2 << endl;
        if (s[i]=='1') base=i+2;
    }
}