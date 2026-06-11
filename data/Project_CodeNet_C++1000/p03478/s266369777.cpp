#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  int ans = 0;
  for(int i = 1; i < N+1; i++){
    int value = i;
    int sum = 0;
    while(value!=0){
      sum += value%10;
      value /= 10;
    }
    if(sum >= A && sum <= B){
      ans += i;
    }
  }
  cout << ans << endl;
}