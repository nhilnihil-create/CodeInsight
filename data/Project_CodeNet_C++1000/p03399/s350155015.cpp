#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  int t,b;
  t=min(A,B);
  b=min(C,D);
  int ans=t+b;
  cout<<ans<<endl;
}