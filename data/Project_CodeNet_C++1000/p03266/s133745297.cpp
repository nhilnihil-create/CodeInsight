#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

//#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int N, K;
  ll ans = 0, cnt=0, cnt2=0;
  cin >> N >> K;

  if(K % 2 == 0){ // Kが偶数の時
    for(int i = 1; i <= N; i++){
      if(i%K == 0) cnt++;
      else if(i % (K/2) == 0) cnt2++;
    }
    // 組み合わせを数える
    // 3つ同じ数の場合
    ans += cnt + cnt2;
    // 2つ同じ数の場合
    ans += (cnt) * (cnt-1) / 2 * 6;
    ans += (cnt2) * (cnt2-1) / 2 * 6;
    // 3つとも違う場合
    ans += (cnt2) * (cnt2-1) * (cnt2 - 2);
    ans += (cnt) * (cnt-1) * (cnt - 2);
  } else { // Kが奇数の時
    for(int i = 1; i <= N; i++){
      if(i%K == 0) cnt++;
    }
    // 組み合わせを数える
    // 3つ同じ数の場合
    ans += cnt;
    // 2つ同じ数の場合
    ans += (cnt) * (cnt-1) / 2 * 6;
    // 3つとも違う場合
    ans += (cnt) * (cnt-1) * (cnt - 2);
  }

  cout << ans << endl;

}
