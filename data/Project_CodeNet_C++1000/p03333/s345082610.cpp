#include<iostream>
#include<algorithm>
#include<climits>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(arg) cin>>arg
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
using namespace std;
typedef long long ll;
int n;
ll l[100010],r[100010];
bool comp(ll &a,ll &b){
  return a>b;
}
int main(){
  scan(n);
  rep(i,n){
    scan(l[i]);scan(r[i]);
  }
  sort(l,l+n,comp);
  sort(r,r+n);
  ll lsum[100010],rsum[100010];
  lsum[0]=0;rsum[0]=0;
  rep1(i,n){
    lsum[i]=lsum[i-1]+l[i-1];
    rsum[i]=rsum[i-1]+r[i-1];
  }
  lsum[n+1]=lsum[n];
  rsum[n+1]=rsum[n];
  ll res=-rsum[1];
  rep1(i,n){
    res=max(res,lsum[i]-rsum[i-1]);
    res=max(res,lsum[i]-rsum[i]);
    res=max(res,lsum[i]-rsum[i+1]);
  }
  prin(res*2);
  
  

    
  
  
  

  return 0;
}
