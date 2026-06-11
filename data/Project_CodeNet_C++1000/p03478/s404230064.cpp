#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int total = 0;
  for(int i = 1; i <= n; i++){
    int sum = 0, temp = i;
    for(int j = 0; j < 5; j++){
      sum += temp % 10;
      temp /= 10;
    }
    if(a <= sum && sum <= b){
      total += i;
    }
  }
  cout << total << endl;
  return 0;
}