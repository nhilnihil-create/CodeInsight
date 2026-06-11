#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  int a=min({A,B,C});
  int b=max({A,B,C});
  int ans=10*b+a+(A+B+C-b-a);
  cout<<ans<<endl;
}