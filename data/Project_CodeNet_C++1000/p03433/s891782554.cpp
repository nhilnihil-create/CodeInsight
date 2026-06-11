#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,N;
  cin >> N >> A;
  for (int X=0; X<=N; X+=500)
  if(N-X<=A){
    cout << "Yes" <<endl;
    return 0;
  }
  cout << "No"<< endl;
}