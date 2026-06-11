#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  
  int count=0;
  while (1){
    for (int i=0; i<N; i++){
      if (A[i]%2 == 0){
        A[i] /= 2;
      }else{
        cout << count << endl;
        return 0;
      }
    }
    count++;
  }
}