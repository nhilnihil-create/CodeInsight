#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;



int main(){
  int N, a, b, c; cin >> N;

  a = N / 100;
  b = (N % 100) / 10;
  c = (N % 10);
  
  cout << (10-a) * 100 + (10-b) * 10 + (10-c) << endl;

}
