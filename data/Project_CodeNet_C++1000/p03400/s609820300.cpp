#include<iostream>
using namespace std;

int main(){
  int N,D,X,sum;
  cin >> N >> D >> X;
  int A;
  sum = N;
  for(int i=0;i<N;i++){
    cin >> A;
    sum += (D-1)/A;
  }
  cout << sum + X << endl;
  return 0;
}