#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
    cin>>N>>A>>B;
  if(A<B){
    cout<<A;
  }
  else{
    cout<<B;
  }
 int sum=A+B-N;
  if(sum<0){
    cout<<" "<<0<<endl;
  }
  else{
    cout<<" "<<sum<<endl;
  }
    
}
