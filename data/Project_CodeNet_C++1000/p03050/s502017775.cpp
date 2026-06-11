#include <bits/stdc++.h>
using namespace std;

// N % m >= ceiling(sqrt(N))のとき
// (商)>(剰余)より m > ceiling(sqrt(N)) >= sqrt(N)
// このとき floor(N/m) < floor(sqrt(N))
// 以上より探索範囲は N % m < ceiling(sqrt(N))
int main(){
  int64_t N;
  cin >> N;

  int64_t ans= 0;
  int64_t rem= 1;
  while(rem* rem < N){
    if((N- rem)% rem==0){
      int64_t div= (N- rem)/ rem;
      if(N/div==rem){
        ans+= div;
      }
    }

    rem++;
  }

  cout << ans << endl;
}