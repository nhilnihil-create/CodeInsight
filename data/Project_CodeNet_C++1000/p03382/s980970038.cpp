#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
comb(a,b)
aはでかいほどいい。bはa/2に近いほどいい
3C0,1,2,3= 3C1or2  3/2or3/2+1
4C0,1,2,3,4=4C2 4/2
*/
int main(){
  ll N, M=0; cin>>N;
  vector<ll> A;
  for(int i=0; i<N; i++){
    ll a; cin>>a;
    A.emplace_back(a);
    M=max(M,a);
  }
  ll second=-1,val=1e9,sep1,sep2;
  sep1=M/2;
  sep2=(M+1)/2;
  for(int i=0; i<N; i++){
    if(A[i]==M) continue;
    ll temp1=abs(sep1-A[i]);
    ll temp2=abs(sep2-A[i]);
    if(temp1<val){
      val=temp1;
      second=i;
    }
    if(temp2<val){
      val=temp2;
      second=i;
    }
  }
  cout<<M<<" "<<A[second]<<endl;
}