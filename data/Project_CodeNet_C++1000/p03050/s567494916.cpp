#include <iostream>
using namespace std;

int main() {
  long long int N; cin >> N;
  long long int ac=N-1;
  if(N==2)  ac=0;
  else{
    for(long long int i=2; i*i<N; i++){
      if(N%i==0 && N%(N/i-1)!=0)  ac+=N/i-1;
    }
  }
  cout << ac;
}