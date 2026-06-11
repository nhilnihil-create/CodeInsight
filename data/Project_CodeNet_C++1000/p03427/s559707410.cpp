#include <bits/stdc++.h>
using namespace std;

int64_t dp(int64_t N){
  if(N < 10) return N;
  else       return max(dp(N/10)+ N%10, dp(N/10- 1)+ 9);
}

int main(){
  int64_t N;
  cin >> N;

  cout << dp(N) << endl;
}