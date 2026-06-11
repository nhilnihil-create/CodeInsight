#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B,C,K;
  cin>>A>>B>>C>>K;
  int Max=max(A,max(B,C));
  int ans=A+B+C+Max*(pow(2,K)-1);
  cout<<ans<<endl;
  
 return 0;
}