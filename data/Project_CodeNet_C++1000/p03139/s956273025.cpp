#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;cin>>N>>A>>B;
 // int X=max(A,B);
  int Y=min(A,B);
  if(A+B<=N) cout<<Y<<" "<<0<<endl;
  else cout<<Y<<" "<<A+B-N<<endl;
}
  
