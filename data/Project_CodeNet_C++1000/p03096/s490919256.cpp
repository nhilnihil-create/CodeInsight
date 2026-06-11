#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
  long Nc;cin>>Nc;
  vector<long>C;
  for(long i=0;i<Nc;i++){
    long c;cin>>c;c--;
    if(i==0||c!=C[C.size()-1])C.push_back(c);
  }
  long N=C.size();Nc=200000;
 
  vector<long>DP(N,1),L(Nc,0);
  for(long i=0;i<N;i++){
    if(i!=0)DP[i]=(DP[i-1]+L[C[i]])%MOD;
    L[C[i]]=(L[C[i]]+(i>0?DP[i-1]:1))%MOD;
  }
  cout<<DP[N-1]%MOD;
}