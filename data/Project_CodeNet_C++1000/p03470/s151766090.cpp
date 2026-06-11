#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i, N){
  	cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  int ans = 1;
  if(N == 1){
  	cout << 1 << endl;
  }else{
  	rep(i, N - 1){
      if(vec.at(i) != vec.at(i + 1)){
      	ans++;
      }
    }
  cout << ans << endl;
  }
  return 0;
}
