#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N; cin >> N;
  vector<bitset<10>> statusOfStores(N);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 10; j++){
      int tmp = 0;
      cin >> tmp;
      if(tmp == 1){
        statusOfStores[i].set(9-j);
      }
    }
  }
  vector<vector<int>> benefits(N, vector<int>(11));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 11; j++){
      cin >> benefits[i][j];
    }
  }
  long long max = -100000000000;
  for(int tmp = 1; tmp < (1 << 10); tmp++){
    bitset<10> s(tmp);
    long long sum = 0;
    for(int i = 0; i < N; i++){
      sum += benefits[i][(s&statusOfStores[i]).count()];
    }
    if(sum > max){
      max = sum;
    }
  }
  cout << max <<endl;
}
