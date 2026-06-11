#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

const int N = 100000;
int main(){
  int q;
  cin >> q;
  vector<bool> prime(N+1, true);
  prime[0] = false;
  prime[1] = false;
  rep(i, N){
    if (prime[i]){
      int x = i*2;
      while(x <= N){
        prime[x] = false;
        x += i;
      }
    }
  }
  vector<int> prime_num(N);
  prime_num[0] = 0;
  rep(i, N+1){
    if (i != 0) prime_num[i] = prime_num[i-1];
    if (prime[i] && prime[(i+1)/2]){
      prime_num[i]++;
    }
  }
  
  int l, r;
  rep(_, q){
    cin >> l >> r;
    cout << prime_num[r] - prime_num[l-1] << endl;
  }
  
  return 0;
}