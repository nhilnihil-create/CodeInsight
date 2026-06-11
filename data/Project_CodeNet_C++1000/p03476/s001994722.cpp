#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<bool> prime(100001, true);
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i <= 100000; i++){
    if (prime[i]){
      for (int j = i * 2;  j <= 100000; j += i){
        prime[j] = false;
      }
    }
  }
  vector<int> S(100002, 0);
  for (int i = 0; i <= 100000; i++){
    if (i % 2 == 1 && prime[i] && prime[(i + 1) / 2]){
      S[i + 1] = S[i] + 1;
    } else {
      S[i + 1] = S[i];
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int l, r;
    cin >> l >> r;
    r++;
    cout << S[r] - S[l] << endl;
  }
}