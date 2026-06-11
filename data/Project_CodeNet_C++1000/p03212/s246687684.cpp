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
int cnt(ll b){
    int res=0;
    map<int,int>mp;
   
    while(b>0){
        mp[b%10]++;
        b/=10;
    }
    bool ok=true;
    if(mp[7]>0&&mp[5]>0&&mp[3]>0)return 1;
    else return 0;
    
}
void dfs(ll a=0){

    if(a<=n){
        ans+=cnt(a);
    }
    else return;

    for(int last=3;last<=7;last+=2){
        a=a*10+last;
        dfs(a);
        a/=10;
    }
}

int main(){
    cin>>n;
    dfs();
    cout<<ans<<endl;
    return 0;
}
