#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,k,n=1;
  cin>>N>>k;
  for(int i=0;i<N;i++){
    if(2*n>n+k)n+=k;
    else n*=2;
  }
  cout<<n<<endl;
}