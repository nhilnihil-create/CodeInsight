#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B;
  cin>>A>>B;
  int K;
  cin>>K;
  long long Q=A;
  long long P=B;
  if(A+K-1>=B-K+1){
    for(long long i=0;i<B-A+1;i++){
      cout<<Q<< endl;
      Q++;
    }
    return 0;
  }
  for(long long i=0;i<K;i++){
    cout<<Q<< endl;
    Q++;
  }
  for(long long i=0;i<K;i++){
    cout<<B-K+1<< endl;
    B++;
  }
}
  
  