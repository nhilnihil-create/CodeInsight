#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}


int N,X;
int x[222222];

int cost(int n){
    int ret=N*X+n*X;

    int coef=0;
    for(int i=1;i<=N;i++){
        int d=x[N-i];
        if(i!=N)d-=x[N-i-1];

        if(i<=n){
            ret+=x[N-i];
            coef+=4;
        }
        else{
            int k=(i-1)/n;
            coef+=2*k+3;
        }
        ret+=coef*d;
    }
    return ret;
}

signed main(){
    cin>>N>>X;
    rep(i,N)cin>>x[i];


    int lb=0,ub=N;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(cost(mid+1)<=cost(mid))lb=mid;
        else ub=mid;
    }
    cout<<cost(ub)<<endl;
    return 0;
}
