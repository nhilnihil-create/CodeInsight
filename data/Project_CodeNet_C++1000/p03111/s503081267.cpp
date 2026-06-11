#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  
  vector<int> A(n);
  rep(i,n) cin>>A[i];
  
  int al,bl,cl,ac,bc,cc,ans,mi=1e9;
  for(int bit=0;bit<(1<<16);bit++){
    al=bl=cl=ac=bc=cc=0;
    for(int i=0;i<n;i++){
      if((bit&(1<<2*i))>0 && (bit&(1<<(2*i+1)))>0){
        al+=A[i];
        ac++;
      }
      else if((bit&(1<<2*i))==0 && (bit&(1<<(2*i+1)))>0){
        bl+=A[i];
        bc++;
      }
      else if((bit&(1<<2*i))>0 && (bit&(1<<(2*i+1)))==0){
        cl+=A[i];
        cc++;
      }
    }
    if(ac==0 || bc==0 || cc==0) continue;
    else if(0<cl && cl<=bl && bl<=al){
      ans=(ac+bc+cc-3)*10+abs(a-al)+abs(b-bl)+abs(c-cl);
      mi=min(mi,ans);
    }
  }
  
  cout<<mi<<endl;
  
  return 0;
}