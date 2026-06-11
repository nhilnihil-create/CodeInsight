#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  long long N, M;
  cin >> N >> M;
  vector<pair<long long, long long>> drink;
  for(int i = 0; i < N; i++){
    int a, b;
    cin >> a >> b;
    drink.emplace_back(a, b);
  }
  sort(drink.begin(), drink.end());
  long long ans = 0;
  for(int i = 0; i < N; i++){
    if(M == 0){
      cout << ans <<endl;
      return 0;
    }
    long long amount = drink[i].second;
    long long price = drink[i].first;
    if(amount <= M){
      ans += price * amount;
      M -= amount;
    } else{
      ans += price * M;
      M = 0;
    }
  }
  cout << ans <<endl;
}
