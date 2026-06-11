#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n,k;

int main(){
    cin>>n>>k;
    double ans=0;
    rep(i,1,n+1){
        //int cnt=0;
        int num=i;
        double p=1.0;
        while(num<k){
            num*=2;
            p/=2;
            //cnt++;
        }
        //rep(j,0,cnt) p*=1/2;
        ans+=p;
    }
    ans/=n;
    cout<<fixed<<setprecision(12)<<ans<<"\n";
    return 0;
}