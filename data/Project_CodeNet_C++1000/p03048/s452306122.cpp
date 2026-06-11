#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int r,g,b,n;

int main(){
    cin>>r>>g>>b>>n;
    int num;
    int ans=0;
    rep(i,0,3001){
        rep(j,0,3001){
            num=(n-i*g-j*b);
            if(num>=0 && num%r==0) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
