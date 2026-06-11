#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  int product = 0;
  for(int i = 1; i <= N; i++){
    int sum = 0;
    int x = i;
    while(x != 0){
      sum += x % 10;
      x /= 10;
    }
    if(sum >= A && sum <= B){
      product += i;
    }
  }
  cout << product << endl;
    
      
      
    
}
  