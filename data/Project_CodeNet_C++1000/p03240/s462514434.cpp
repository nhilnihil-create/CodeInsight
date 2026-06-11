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
  ll N, x, y;
  cin >> N;
  vector<pair<pair<int, int>,ll > > h(N);

  rep(i, N){
    cin >> h[i].first.first >>  h[i].first.second >> h[i].second;
  }

  ll H, cnt = 0;
  map<ll, int> m;
  // i-jを答えとして全探索を行う
  rep(i, 101){ // X
    rep(j, 101) { // Y
      m.clear();
      cnt = 0;
      rep(k, N){ // 間違っていないかを確認する
        if(h[k].second == 0) continue;
        cnt++;
        H = abs(h[k].first.first - i) + abs(h[k].first.second - j) + h[k].second;
        if(m.find(H)==m.end()){
          m.insert(make_pair(H, 1));
        } else {
          m[H]++;
        }
      }
      
      if (m.size()==1 && cnt > 1){
        printf("%d %d %lld\n", i, j, H);
        return 0;
      }
    }
  }
  rep(i, N){
    if(h[i].second == 0) continue;
    printf("%d %d %lld\n", h[i].first.first, h[i].first.second, h[i].second);
  }
}
