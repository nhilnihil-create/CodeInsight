#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K;
  cin>>N>>K;
  if(N==K)
    cout<<1<<endl;
  else
  cout<<2+(N-K-1)/(K-1)<<endl;
   return 0;
}