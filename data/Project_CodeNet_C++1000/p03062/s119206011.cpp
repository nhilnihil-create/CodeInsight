#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,j=0;
  cin>>N;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    if(i<0){
      j++;
    }
  }
  int k=0,mi=1000000000;
  for(int i:A){
    k+=abs(i);
    mi=min(mi,abs(i));
  }
  if(j%2==0)
    cout<<k<<endl;
  else
    cout<<k-mi*2<<endl;
}