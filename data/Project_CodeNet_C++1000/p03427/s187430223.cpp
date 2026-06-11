#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    ll res=0;
    ll m=n, cnt=0;
    while(m>0){
        res+=m%10;
        m/=10;
    }
    m=n;
    while(m>10){
        cnt++;
        m/=10;
    }
    chmax(res, 9*cnt+m-1);
    cout<<res<<endl;
    return 0;
}