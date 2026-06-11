#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>//pair
#include<cmath>//abs,sqrt
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using std::cin;
using std::min;
using std::max;
typedef long long ll;
const int INF=1e+9;
const ll INFLL=1e+17;
int N;
ll A[200010];
ll sum[200010];
void addsum(){
  sum[0]=0;
  rep1(i,N){
    sum[i]=sum[i-1]+A[i-1];
  }
}
ll B(int l){
  return sum[l+1];
}
ll C(int l,int i){
  return sum[i+1]-sum[l+1];
}
ll D(int r,int i){
  return sum[r+1]-sum[i+1];
}
ll E(int r){
  return sum[N]-sum[r+1];
}
ll delL(int l,int i){
  return std::abs(B(l)-C(l,i));
}
int searchL(int s,int i){
  while(delL(s-1,i)-delL(s,i)>=0) s++;
  return s-1;
}
ll delR(int r,int i){
  return std::abs(D(r,i)-E(r));
}
int searchR(int s,int i){
  while(delR(s-1,i)-delR(s,i)>=0) s++;
  return s-1;
}
ll solve(){
  ll res=INFLL;
  addsum();
  int sl=0,sr=2;
  for(int i=1;i<=N-1;i++){
    sl=searchL(sl,i);
    sr=searchR(sr,i);
    ll b=B(sl),c=C(sl,i),d=D(sr,i),e=E(sr);
    ll mi=min(min(b,c),min(d,e)),ma=max(max(b,c),max(d,e));
    res=min(res,ma-mi);
  }
  return res;
}
int main(){
  cin>>N;
  rep(i,N) cin>>A[i];
  prin(solve());
  return 0;
}
