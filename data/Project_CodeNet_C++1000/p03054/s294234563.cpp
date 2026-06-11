#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define mod 1000000007
using namespace std;
typedef long long ll;
bool chmax(ll &a,ll b){
    if(a>b)return 0;
    a=b; return 1;
}
bool chmin(ll &a,ll b){
    if(a<b)return 0;
    a=b; return 1;
}
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

ll h,w,n;
ll sx,sy;
string s,t;
bool solve(){
    ll l=1,r=w;
    for(int i=n-1;i>=0;i--){
	if(t[i]=='L')r++; chmin(r,w);
	if(t[i]=='R')l--; chmax(l,1); //cout<<l<<" "<<r<<endl;
	if(l>r)return 0;
	if(s[i]=='R')r--; //chmax(r,1);
	if(s[i]=='L')l++; //chmin(l,h); 
      //cout<<l<<"#"<<r<<endl;
	if(l>r)return 0;
    }
  //cout<<l<<" "<<r<<endl;
    if(not(l<=sx&&sx<=r))return 0;
    
    l=1,r=h;
    for(int i=n-1;i>=0;i--){
	if(t[i]=='U')r++; chmin(r,h);
	if(t[i]=='D')l--; chmax(l,1);
	if(l>r)return 0;
	if(s[i]=='D')r--; //chmax(r,1);
	if(s[i]=='U')l++; //chmin(l,w);
	if(l>r)return 0;
    }
    if(not(l<=sy&&sy<=r))return 0;
    
    return 1;
}
int main(){
    cin>>h>>w>>n;
    cin>>sy>>sx;
    cin>>s>>t;
    cout<<(solve()?"YES":"NO")<<endl;
}


