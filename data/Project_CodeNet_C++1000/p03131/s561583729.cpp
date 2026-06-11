#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

ll k,a,b;

int main(){
    cin>>k>>a>>b;
    ll ans;
    if(a>=b || b-a==1){
        ans=k+1;
    }
    else{
        ll now=1;
        while(k>0){
            if(now<a){
                now++;
                k--;
            }
            else if(k>1){
                now=now-a+b;
                k-=2;
            }
            else if(k=1){
                now++;
                k--;
            }
        }
        ans=now;
    }
    cout<<ans<<"\n";
    return 0;
}
