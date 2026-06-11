#include<bits/stdc++.h>
#define REP(i,x) for(int i=0,i##_len=(x);i<i##_len;++i)
#define rep(i,a,b) for(int i=(a),i##_len(b);i<i##_len;++i)
#define All(x) begin(x),end(x)
#define rAll(x) rbegin(x),rend(x)
using namespace std;
using ll = long long;

int main(){
    ll n,m,d;cin>>n>>m>>d;
    ll ans=0;
    if(d<=n){
        if(d==0) ans=n;
        else if(2*d<=n) ans=d+2*(n-2*d)+d;
        else ans=2*(n-d);
    }
    else{
        cout<<0<<endl;
        return 0;
    }
    double res=ans*(m-1)/double(n*n);
    printf("%.16f\n",res);
}
