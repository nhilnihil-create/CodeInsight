#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n,y;

int main(){
    cin>>n>>y;

    bool flag=false;
    int ans1,ans2,ans3;
    rep(i,0,n+1){
        rep(j,0,n+1){
            if(n-i-j<0) continue;
            if(10000*i+5000*j+1000*(n-i-j)==y){
                ans1=i;
                ans2=j;
                ans3=n-i-j;
                flag=true;
                break;
            }
        }
    }
    if(flag) cout<<ans1<<" "<<ans2<<" "<<ans3<<"\n";
    else cout<<-1<<" "<<-1<<" "<<-1<<"\n";
    return 0;
}
