#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int sum = 0;
    int x = i;
    for(int i = 0; i < 5; i++){
      sum += x % 10;
      x /= 10;
    }
    if(a <= sum && sum <= b){
      ans += i;
    }
  }
  cout << ans << endl;
}