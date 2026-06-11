#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  bitset<30> B(0);
  int k;
  cin>>k;
  for(int l=0;l<k;l++){
    int A;
    cin>>A;
    B.set(A-1);
  }
  for(int i=1;i<N;i++){
    int K;
    cin>>K;
    bitset<30> C(0);
    for(int j=0;j<K;j++){
      int A;
      cin>>A;
      C.set(A-1);
    }
    B&=C;
  }
  cout<<B.count()<<endl;
}