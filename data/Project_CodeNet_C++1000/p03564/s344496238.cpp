#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  int b=1;
  int i=0;
  for(;b<K&&i<N;i++){
    b*=2;
  }
  for(;i<N;i++){
    b+=K;
  }
  cout<<b<<endl;
}
