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
    ll a,b;
    cin>>a>>b;
   
    //odd
    if(b%2==1){
        if((b+1)%4==0)b=0;
        else b=1;
    }
    //even
    else if(b%4!=0)b^=1;

    if(a==0){
        ll ans=b^a;
        cout<<ans<<endl;
        return 0;
    }
    a--;
    if(a%2==1){
        if((a+1)%4==0)a=0;
        else a=1;
    }
    //even
    else if(a%4!=0)a^=1;
    
    ll ans=a^b;
    cout<<ans<<endl;
    return 0;
}