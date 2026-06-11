#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,M;
  cin>>N>>M;
  if(N==1&&M==1)cout<<1;
  else if(N==1||M==1)cout<<N+M-3;
  else{cout<<(N-2)*(M-2);}
}