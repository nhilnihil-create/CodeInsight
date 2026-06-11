#include <iostream>
#include <map>
using namespace std;

template <class T> inline bool chmax(T& a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  map<int, int> ps;
  int p;
  for(int i = 0; i < N; ++i) {
    cin >> p;
    ps[p] = i;
  }

  int count = 0;
  int max = 0;
  int prev = -1;
  for(auto p : ps) {
    if(prev > p.second) { // index が増加している間はcountをアップ
      count = 0;
    }
    count++;
    chmax(max, count);
    prev = p.second;
  }
  cout << N - max << endl;
  return 0;
}