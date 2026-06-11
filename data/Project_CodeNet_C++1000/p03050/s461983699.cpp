#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint ans;

vector<lint> enum_divisors(lint N) {
    vector<lint> res;
    for (lint i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

signed main(){
  lint N; cin >> N;
  vector<lint> num = enum_divisors(N);
  lint ans = 0;
  for(lint i = 0; i < num.size(); i++){
    lint x = N / num[i];
    if(num[i] > x + 1) ans += (num[i] - 1);
  }
  cout << ans << endl;
}