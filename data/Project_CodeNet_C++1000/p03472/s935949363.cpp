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
  ll N, H, a, b;
  cin >> N >> H;
  vector<pair<ll, ll> > h;

  rep(i, N){
    cin >> a >> b;
    h.push_back(make_pair(a, 0));
    h.push_back(make_pair(b, 1));
  }

  sort(h.begin(), h.end());

  ll cnt = 0;
  for(int i = h.size() - 1; i >= 0; i--){
    H -= h[i].first;
    cnt++;
    if(H <= 0) break;
    if(h[i].second == 0){
      if(H%h[i].first != 0) cnt++;
      cnt += H/h[i].first;
      break;
    }
  }

  print(cnt);

}
