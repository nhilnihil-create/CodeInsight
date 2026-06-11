#include <bits/stdc++.h>
using namespace std;
int S(long long n){
  string s = to_string(n);
  int d = s.size();
  int ans = 0;
  for (int i = 0; i < d; i++){
    ans += s[i] - '0';
  }
  return ans;
}
int main(){
  int K;
  cin >> K;
  vector<long long> p;
  for (int i = 1; i < 1000; i++){
    string s = to_string(i);
    while (s.size() <= 15){
      p.push_back(stoll(s));
      s += '9';
    }
  }
  sort(p.rbegin(), p.rend());
  p.erase(unique(p.begin(), p.end()), p.end());
  long long tmp = 1000000000000000;
  int s = 1;
  vector<long long> snuke;
  for (long long i : p){
    if (tmp * S(i) >= s * i){
      snuke.push_back(i);
      tmp = i;
      s = S(i);
    }
  }
  sort(snuke.begin(), snuke.end());
  for (int i = 0; i < K; i++){
    cout << snuke[i] << endl;
  }
}