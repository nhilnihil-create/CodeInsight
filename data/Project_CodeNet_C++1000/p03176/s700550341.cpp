#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
  int N;
  cin>>N;
  int h[200000];
  for(int i=0;i<N;i++) cin>>h[i];
  pair<int,pair<long long,int>> flo[200001];
  for(int i=0;i<N;i++){
    long long a; cin>>a;
    flo[i]=make_pair(h[i],make_pair(a,i));
  }
  sort(flo,flo+N);
  flo[N]=make_pair(N+1,make_pair(0,N));
  long long tree[1000000];
  int l=1;
  while(l<N+1) l*=2;
  for(int i=1;i<l*2;i++) tree[i]=0;
  for(int i=0;i<=N;i++){
    int x=flo[i].second.second;
    long long v=0;
    int n=l+x;
    while(n!=0){
      v=max(v,tree[n]); n/=2;
    }
    tree[l+x]=flo[i].second.first+v;
    int L=l+x+1; int R=l*2-1;
    while(R-L>0){
      if(L%2==0){
        L/=2;
        if(R%2==0){
          tree[R]=max(tree[R],tree[l+x]); R=(R-1)/2;
        }
        else R/=2;
      }
      else{
        tree[L]=max(tree[L],tree[l+x]); L=(L+1)/2;
        if(R%2==0){
          tree[R]=max(tree[R],tree[l+x]); R=(R-1)/2;
        }
        else R/=2;
      }
    }
    if(L==R) tree[L]=max(tree[L],tree[l+x]);
  }
  cout<<tree[l+N]<<endl;
  
  return 0;
}