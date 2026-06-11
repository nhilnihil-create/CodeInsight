#include<iostream>
using namespace std;
int main(){
  int N, A[100];
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  int min=A[0], max=A[0];
  for(int j=1; j<N; j++){
    if(A[j] < min) min = A[j];
    if(A[j] > max) max = A[j];
  }
  cout << abs(max - min);
  return 0;
}