#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;

int ans=0;
int n;

void dfs(ll a=0,int b=0){

    if(a<=n){
        if(b==7)ans++;
    }
    else return;

    for(int last=3;last<=7;last+=2){
        a=a*10+last;
        if(last==3)dfs(a,b|1);
        if(last==5)dfs(a,b|2);
        if(last==7)dfs(a,b|4);
        a/=10;
    }
}

int main(){
    cin>>n;
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
