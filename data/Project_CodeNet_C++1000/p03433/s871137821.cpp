#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A;
  cin >> N >> A;
  if(N % 500 == N){
    if(N <= A){
      cout << "Yes";
    }
    else{
      cout << "No";
    }
  }
    else{
      if(N - N/500 * 500 <= A){
         cout << "Yes";
      }
      else{
        cout << "No";
      }
    }
}