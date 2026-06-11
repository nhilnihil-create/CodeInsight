#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,cnt=1;
  cin >> N;
  vector<int>v(N);
  for (int i=0; i<N; i++) cin >> v.at(i);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int x = v.at(0);
  for (int i=1; i<N; i++){
    if (x > v.at(i)){
      cnt++;
      x = v.at(i);
    }
  }
  cout << cnt << endl;
}
