#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

long long  n;

int main(){
  cin >> n;
  long long sum = 0;
  for(long long  i = 1; i <= sqrt(n) + 100; i++){
    if(n % i == 0){
      long long num = n / i - 1;
      if(num <= i) break;
      sum += num;
    }
  }
  cout << sum << endl;
  return 0;
}
