#include<bits/stdc++.h>
using namespace std;
int main(){
  long long A; long long B; long long C;
  cin>>A>>B>>C;
   long long N; cin>>N;
  if(abs(A-B)>1000000000000000000)
    cout<<"Unfair"<<endl;
  else if(N%2==0)
    cout<<A-B<<endl;
  else cout<<B-A<<endl;
}