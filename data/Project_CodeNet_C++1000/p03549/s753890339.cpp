#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  cout<<(M*1900+(N-M)*100)*pow(2,M)<<endl;
  return 0;
}

  
  
  