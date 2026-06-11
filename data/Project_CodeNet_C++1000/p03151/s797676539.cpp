#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  ll Asum = 0;
  ll Bsum = 0;
  rep(i, N){
    cin >> A.at(i);
    Asum += A.at(i);
  }
  rep(i, N){
    cin >> B.at(i);
    Bsum += B.at(i);
  }
  if(Asum < Bsum){
    cout << -1 << endl;
    return 0;
  }
  
  vector<int> sub(N);
  ll micnt = 0;
  ll shortage = 0;
  rep(i, N){
    sub.at(i) = A.at(i) - B.at(i);
    if(sub.at(i) < 0){
      shortage += sub.at(i);
      micnt++;
    }
  }
  ll cnt = 0;
  sort(sub.begin(), sub.end(), greater<int>());
  while(shortage < 0){
    shortage += sub.at(cnt);
    cnt++;
  }
  cout << micnt + cnt << endl;
}