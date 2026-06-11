#include <iostream>
using namespace std;
 
int main(){
  int N;
  long long int A[201];
  long long int max=0;
  long long int min=1000000000;
  cin >> N;
  for(int i=0; i<N ;++i){
    cin >> A[i];
    if(A[i]>max) max=A[i];
    if(A[i]<min) min=A[i];
  }
  cout << max-min <<endl;
}