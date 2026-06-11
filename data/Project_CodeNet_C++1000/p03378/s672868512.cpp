#include<iostream>
using namespace std;

int main(){
  int N,M,X,R=0,L=0;
  cin >> N >> M >> X;
  int A[N+1];
  for(int i=0;i<N+1;i++){
    A[i] = 0;
  }
  for(int i=0;i<M;i++){
    int x;
    cin >> x;
    A[x] = 1;
  }
  for(int i=0;i<X;i++){
    R += A[i];
  }
  for(int i=X;i<N+1;i++){
    L += A[i];
  }
  cout << min(R,L) << endl;
  return 0;
}