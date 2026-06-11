#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int FindSumOfDigits(int n){
  int sum = 0;
  while(n > 0){
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}

int main(void){
  int N, A, B;
  cin >> N >> A >> B;
  int total = 0;
  for(int i = 1; i <= N; i++){
    int sum = FindSumOfDigits(i);
    if(A <= sum && sum <= B){
      total += i;
    }
  }
  cout << total << endl;
  return 0;
}