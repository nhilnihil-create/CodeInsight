#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
int main() {
  long long n, k;
  cin >> n >> k;
  bitset<40> bitK(k);
  vector<bitset<40>> bitA(n);
  for(int i=0;i<n;i++) {
    long long a;
    cin >> a;
    bitset<40> ba(a);
    bitA[i] = ba;
  }
  vector<long long> setted(40);
  for(int i=0;i<n;i++) {
    for(int j=0;j<40;j++) {
      if(bitA[i].test(j)) setted[j]++;
    }
  }
  long long ans = 0;
  // x == 0
  for(int i=0;i<40;i++) {
    ans += (long long)pow(2, i) * setted[i];
  }
  // x == k
  long long alt = 0;
  for(int i=0;i<40;i++) {
    if(bitK.test(i)) alt += (long long)pow(2, i) * (n - setted[i]);
    else alt += (long long)pow(2, i) * setted[i];
  }
  chmax(ans, alt);
  for(int i=0;i<40;i++) {
    long long tmp = 0;
    if(!bitK.test(i)) continue;
    bitset<40> x;
    for(int j=0;j<i;j++) {
      tmp += (long long)pow(2, j) * max(n - setted[j], setted[j]);
    }
    tmp += pow(2, i) * setted[i];
    for(int j=i+1;j<40;j++) {
      if(bitK.test(j)) {
        tmp += (long long)pow(2, j) * (n - setted[j]);
      }
      else {
        tmp += (long long)pow(2, j) * setted[j];
      }
    }
    chmax(ans, tmp);
  }
  cout << ans << endl;
}
