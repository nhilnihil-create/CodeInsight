#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> S(N+1);
  S.at(0) = 0;
  for(int i=0;i<N;i++){
    cin >> A.at(i); 
    S.at(i+1) = S.at(i) + A.at(i);
  }
  map<long long, long long> cnt;
  for(int i=0;i<N+1;i++){
    cnt[S.at(i)] ++;
  }
  long long res=0;
  for(auto p : cnt){
    long long num = p.second;
    res += num * (num - 1) / 2;
  }
 
  cout << res << endl;
}