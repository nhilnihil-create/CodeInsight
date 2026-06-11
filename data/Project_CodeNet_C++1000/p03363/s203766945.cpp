#include<bits/stdc++.h>
#include<set>
#include<map>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<long long>A(N);
  for (int i = 0; i < N; i ++) cin >> A[i];
  vector<long long>sum(N + 1);
  map<long long, long long>f_s;
  sum[0] = 0;
  for (int i = 0; i < N; i ++) {
    sum[i + 1] = sum[i] + A[i];
    f_s[sum[i + 1]] ++;
  }
  long long ans = 0;
  for (int i = 0; i < N; i ++) {
    ans += f_s[sum[i]];
    f_s[sum[i + 1]] --;
  }
  cout << ans << endl;
}

