#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp(a,b) std::make_pair(a,b)
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
int N;
ll a[60];
void solve(){
  //絶対値最大を探す
  int j,max=0;
  rep(i,N){
    if(max<=std::abs(a[i])){
      j=i;
      max=std::abs(a[i]);
    }
  }
  prin(2*N-1);
  //絶対値最大を全ての要素に足す
  rep(i,N){
    a[i]+=a[j];
    prin2(j+1,i+1);
  }
  //a[j]の符号によって処理が分かれる
  if(a[j]>=0){
    //a[i]にa[i-1]を足す(i=1から)
    rep1(i,N-1){
      a[i]+=a[i-1];
      prin2(i,i+1);
    }
  }
  else{
    //a[i-1]にa[i]を足す(i=N-1から)
    for(int i=N-1;i>0;i--){
      a[i-1]+=a[i];
      prin2(i+1,i);
    }
  }
  /* rep(i,N){
    std::cout<<a[i]<<" ";
  }
  std::cout<<"\n";*/
}
int main(){
  cin>>N;
  rep(i,N) cin>>a[i];
  solve();
  return 0;
}
