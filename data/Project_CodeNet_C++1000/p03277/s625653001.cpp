#include <bits/stdc++.h>
using namespace std;
int INF = 1000000001;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  int tv = 0;
  int fv = INF;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    vector<int> b(N);
    for (int i = 0; i < N; i++){
      if (a[i] < mid){
        b[i] = 1;
      } else {
        b[i] = -1;
      }
    }
    vector<int> S(N + 1, 0);
    for (int i = 0; i < N; i++){
      S[i + 1] = S[i] + b[i];
    }
    vector<int> S2 = S;
    sort(S2.begin(), S2.end());
    S2.erase(unique(S2.begin(), S2.end()), S2.end());
    int cnt = S2.size();
    map<int, int> mp;
    for (int i = 0; i < cnt; i++){
      mp[S2[i]] = i;
    }
    for (int i = 0; i <= N; i++){
      S[i] = mp[S[i]];
    }
    vector<int> BIT(cnt + 1, 0);
    long long ans = 0;
    for (int i = 0; i <= N; i++){
      int j;
      j = S[i];
      while (j > 0){
        ans += BIT[j];
        j -= j & -j;
      }
      j = S[i] + 1;
      while (j <= cnt){
        BIT[j]++;
        j += j & -j;
      }
    }
    if (ans <= (long long) N * (N + 1) / 4){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}