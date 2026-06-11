#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int j=1;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    if(A%2==0)
      j*=2;
  }
  cout<<(int)pow(3,N)-j<<endl;
}