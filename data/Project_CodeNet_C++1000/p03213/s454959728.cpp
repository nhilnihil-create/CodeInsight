#include <iostream>
#include <vector>
#include <map>

using namespace std;

void primals(int x, vector<int> &ret){
  for (int i=2; i<=x; i++){
    if (ret.size() == 0) ret.push_back(i);
    else{
      bool f = true;
      for (int p : ret){
        if (i % p == 0){
          f = false;
          break;
        }
      }
      if (f) ret.push_back(i);
    }
  }
  return;
}
      

void calc_all_divisor(int x, map<int, int> &ret, vector<int> &primals){
  int c = 0;
  while (c < primals.size()){
    if (x % primals[c] != 0){
      c++;
    }
    else {
      ret[primals[c]]++;
      x = x / primals[c];
    }
  }
  return;
}
    

int main(){
  int N;
  cin >> N;
  vector<int> P;
  primals(N, P);

  map<int, int> divisor;
  for (int i=2; i<=N; i++){
    calc_all_divisor(i, divisor, P);
  }
  for (auto e : divisor) cerr << e.first << " " << e.second << "\n";
  int N3 = 0, N5 =0, N15 = 0, N25= 0, N75 = 0;
  for (auto e : divisor){
    if (e.second >= 75 - 1) N75++;
    if (e.second >= 25 - 1) N25++;
    if (e.second >= 15 - 1) N15++;
    if (e.second >= 5 - 1) N5++;
    if (e.second >= 3 - 1) N3++;
  }
  int ans = 0;
  ans += N75;
  ans += N25 * max(0, N3 - 1);
  ans += N15 * max(0, N5 - 1);
  ans += N5 * max(0, N5 - 1) * max(0, N3 - 2) / 2;
  cout << ans << "\n";
  return 0;
}