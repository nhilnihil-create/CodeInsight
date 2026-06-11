#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
ll n,a[(1<<18)];
ll fi[(1<<18)],sc[(1<<18)];
int main(){
  cin>>n;
  for(int i=0;i<(1<<n);i++){
      cin>>a[i];
      fi[i]=a[i];
      sc[i]=-1;
  }
  ll rui=-1;
  for(int j=0;j<n;j++)for(int i=0;i<(1<<n);i++){
      if((i&(1<<j))>0){
          if(fi[i]<fi[i-(1<<j)]){
              sc[i]=fi[i];
              fi[i]=fi[i-(1<<j)];
          }
          else if(sc[i]<fi[i-(1<<j)]){
              sc[i]=fi[i-(1<<j)];
          }
          if(fi[i]<sc[i-(1<<j)]){
              sc[i]=fi[i];
              fi[i]=sc[i-(1<<j)];
          }
          else if(sc[i]<sc[i-(1<<j)]){
              sc[i]=sc[i-(1<<j)];
          }
      }
  }
  for(int i=1;i<(1<<n);i++){
      chmax(rui,fi[i]+sc[i]);
      cout<<rui<<endl;
  }
  return 0;
}
