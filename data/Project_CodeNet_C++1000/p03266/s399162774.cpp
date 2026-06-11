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


int main(){
    int n,k;
    cin>>n>>k;
    ll x=0,y=0;
    bool ok=(k%2==0)?true:false;
    arep(i,1,n+1){
        if(i%k==0)x++;
        if(ok&&i%k==(k/2))y++;
    }
    ll ans=0;
    ans+=x*x*x;
    ans+=y*y*y;
    cout<<ans<<endl;

    return 0;
}