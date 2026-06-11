#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int digit(int n){
  int sum = 0;
  while(n>0){
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main(){
  int n;
  cin >> n;
  int curMin = 1e8;
  for(int i = 1; i < n; i++){
    curMin = min(curMin, digit(i)+digit(n-i));
  }
  cout << curMin << endl;
  return 0;
}