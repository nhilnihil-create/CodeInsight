#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int N, ss, sum = 0;
  cin >> N;
  vector<int> s(N); // 開会式N病後
  vector<int> c(N); // 累積和を作成する
  vector<int> f(N);
  vector<int> ans(N);

  rep(i, N-1){
    cin >> c[i] >> s[i] >> f[i];
  }

  for (int i = 0; i < N; i++) // i番目の駅について
  {
    int t = 0;
    for (int j = i; j < N - 1; j++) // 先のところを見る
    {
      if (t < s[j])
        t = s[j];
      else if (t % f[j] == 0){
        // 何もしない;
      }
      else {
        t = t + f[j] - t % f[j];
      }
      t += c[j];
    }
    printf("%d\n", t);
  }

}
