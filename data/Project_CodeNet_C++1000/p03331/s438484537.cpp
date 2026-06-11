#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 1; i < (int)(n); i++)

int sum_Digits(int n){
  int sum = 0;
  while(n > 0){
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main(){
  int N, min = 10e5;
  cin >> N;
  rep(a, N){
    int b = N - a;
    int tmp = sum_Digits(a) + sum_Digits(b);
    if(min > tmp){
      min = tmp;
    }
  }
  cout << min << endl;
}