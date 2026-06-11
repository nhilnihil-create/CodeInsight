#include <bits/stdc++.h>
using namespace std;

bool primeOrNot(int x){
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0){
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int Q; cin >> Q;
  vector<pair<int, int>> query;
  vector<int> like2017(100001);
  like2017[1] == 0;
  for(int i = 0; i < Q; i++){
    int a, b; cin >> a >> b;
    query.emplace_back(a, b);
  }
  unordered_set<int> primeset;
  primeset.insert(2);
  for(int i = 3; i <= 100000; i+=2){
    like2017[i] = like2017[i-2];
    if(primeOrNot(i)){
      primeset.insert(i);
    }
    if(primeset.count(i) && primeset.count((i + 1) / 2)){
      like2017[i] ++;
    }
 }
  for(int i = 0; i < Q; i++){
    cout << like2017[query[i].second] - like2017[max(query[i].first-2, 0)] <<endl;
  }
}
