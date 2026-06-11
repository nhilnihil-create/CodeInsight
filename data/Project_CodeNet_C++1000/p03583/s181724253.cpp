#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

long long int N;

void solve(int N){
  long long int res1, res2, res3;
  for(long long int h = 1; h <= 3500; h++){
    for(long long int n = 1; n <= 3500; n++){
      long long int a = N * h * n;
      long long int b = 4*h*n - N*n - N*h;
      if(b <= 0){
        continue;
      }
      if(a % b == 0){
        res1 = h;
        res2 = n;
        res3 = a / b;
        cout << res1 <<" "<< res2 <<" "<< res3 << endl;
        return;
      }
    }
  }
  return;
}

int main(){
  cin >> N;
  solve(N);
  return 0;
}
