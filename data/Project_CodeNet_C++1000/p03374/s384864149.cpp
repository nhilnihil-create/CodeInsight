#include<iostream>
#include<cstdio>
#define N 100005
using namespace std;

typedef long long ll;
ll n,c,s,ans,x[N],cal[N],mx[N]={0},mx2[N]={0};
int main(){
  ll i;
  cin>>n>>c;
  for(i=0;i<N;i++){
    scanf("%lld %lld",&x[i],&cal[i]);
  }  
  //clockwise
  for(i=n-1;i>=0;i--){
    s+=cal[i];//consumed calories
    mx[i] = max(mx[i+1],s-(c-x[i]));//c-x[i]: used calories
    mx2[i] = max(mx2[i+1],s-(c-x[i])*2);//return first point
  }
  
  ans = max(mx[0],mx2[0]);
  s=0;//initialize calories
  
  //anticlockwise
  for(i=0;i<n;i++){
    s+=cal[i];
    ans = max(ans, s-x[i]*2 + mx[i+1]);//return first point 
    ans = max(ans, s-x[i] + mx2[i+1]);
  }
  cout << ans;
  return 0;
}
