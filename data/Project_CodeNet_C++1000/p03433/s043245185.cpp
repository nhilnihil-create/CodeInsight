#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,N;
  int OK= 1;
  cin >> N >> A;
  for (int X=0; X<=N; X+=500){
    if(N-X<=A){
      OK=2;
    }
  }
  if(OK==2){
    cout << "Yes" <<endl;
  }
  else{
    cout << "No" <<endl;
  }
}