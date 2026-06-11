#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B, count = 0;
  cin >> A >> B;
  int N = B - A + 1;
  rep(i, N){
    int K = (A + i) / 1000;
    int L = (A + i) % 100;
    if(K / 10 == L % 10 && K % 10 == L / 10){
     count++;
     }
   }
   cout << count <<endl;
   return 0;   
}