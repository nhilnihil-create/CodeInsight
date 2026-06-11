#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,M;
  cin>>N>>M;
  long long T=M*1900+(N-M)*100;
  long long Ans=T;
  for(int i=0;i<M;i++){
    Ans=2*Ans;
  }
  cout<<Ans<<endl;
}
