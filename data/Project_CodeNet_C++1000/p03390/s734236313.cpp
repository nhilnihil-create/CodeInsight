#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
ll f(ll x,ll y,ll s){
    ll sq=(ll)sqrt(s);
    if(x<=sq){
	return min(x,s/y);
    }
    
    ll sh=s/(sq+1);
    if(sh==s/sq)sh--;
    return min(x-sq,sh-y+1)+sq;
}
int main(){
    int q;cin>>q;
    lol(u,q){
	ll a,b;cin>>a>>b;
	ll x=f(a-1,b+1,a*b-1);
	ll y=f(b-1,a+1,a*b-1);
	cout<<x+y<<endl;
    }
    return 0;
}
