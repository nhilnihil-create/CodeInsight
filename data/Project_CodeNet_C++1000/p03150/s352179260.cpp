#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    string s; cin>>s;
    string key="keyence";
    ll n=s.size();
    ll a=0, b=0;
    rep(i,n){
        if(s[i]==key[i]) a++;
        else break;
    }
    rep(i,n){
        if(s[n-1-i]==key[6-i]) b++;
        else break;
    }
    if(a+b>=7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}