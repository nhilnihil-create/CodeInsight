#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000;
int main(){
  int A, B, Q;
  cin >> A >> B >> Q;
  set<long long> st1;
  for (int i = 0; i < A; i++){
    long long s;
    cin >> s;
    st1.insert(s);
  }
  set<long long> st2;
  for (int i = 0; i < B; i++){
    long long t;
    cin >> t;
    st2.insert(t);
  }
  for (int i = 0; i < Q; i++){
    long long x;
    cin >> x;
    long long L1, R1, L2, R2;
    if (st1.count(x)){
      L1 = 0;
      R1 = 0;
    } else {
      auto itr = st1.lower_bound(x);
      if (itr == st1.end()){
        R1 = INF;
      } else {
        R1 = *itr - x;
      }
      if (itr == st1.begin()){
        L1 = INF;
      } else {
        L1 = x - *prev(itr);
      }
    }
    if (st2.count(x)){
      L2 = 0;
      R2 = 0;
    } else {
      auto itr = st2.lower_bound(x);
      if (itr == st2.end()){
        R2 = INF;
      } else {
        R2 = *itr - x;
      }
      if (itr == st2.begin()){
        L2 = INF;
      } else {
        L2 = x - *prev(itr);
      }
    }
    long long ans = INF;
    ans = min(ans, max(L1, L2));
    ans = min(ans, max(R1, R2));
    ans = min(ans, L1 * 2 + R2);
    ans = min(ans, R1 * 2 + L2);
    ans = min(ans, L2 * 2 + R1);
    ans = min(ans, R2 * 2 + L1);
    cout << ans << endl;
  }
}