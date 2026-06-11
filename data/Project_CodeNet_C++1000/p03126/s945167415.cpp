#include<iostream>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  int C[M]={0};
  for(int i=0; i<N; i++){
    int K;
    cin >> K;
    for(int j=0; j<K; j++){
      int A;
      cin>>A;
      C[A-1]++;
    }
  }
  int count=0;
  for(int i=0; i<M; i++){
    if(C[i]==N) count++;
  }
  cout << count << endl;
  return 0;
}