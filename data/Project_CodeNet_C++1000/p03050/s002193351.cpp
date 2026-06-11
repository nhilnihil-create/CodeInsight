#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,Z=0;
  cin>>N;
  for(int64_t i=1;i*i<N;i++){
    if(N%i==0&&i*(i+1)!=N){
      Z+=N/i;
      Z--;
    }
  }
  cout<<Z<<endl;
}