#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  long sumA = 0, sumB = 0;
  long ng = 0;
  vector<long> ok, a(N), b(N);
  for(int i = 0; i < N; i++)cin >> a.at(i);
  for(int i = 0; i < N; i++)cin >> b.at(i);
  for(int i = 0; i < N; i++){
    sumA += a.at(i);
    sumB += b.at(i);
    if(a.at(i) >= b.at(i)){
      ok.push_back(a.at(i) - b.at(i));
    } else {
      ng += b.at(i) - a.at(i);
    }
  }
  if(sumA < sumB){
    cout << -1 << endl;
    return 0;
  } else if(ng == 0){
    cout << 0 << endl;
    return 0;
  }
  sort(ok.begin(), ok.end());
  long co = 0;
  for(int i = ok.size() - 1; i >= 0; i--){
    co += ok.at(i);
    if(ng <= co){
      cout << N - i << endl;
      return 0;
    }
  }
}