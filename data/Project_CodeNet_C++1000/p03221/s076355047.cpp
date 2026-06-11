#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

int MOD = 1e9+7;

ostringstream sout;
string zero_padding(int num){
  sout << setfill('0') << setw(6) << num;
  string ret = sout.str();
  return ret;
}

int main(){
  int N, M;
  cin >> N >> M;
  map<int, vector<ipair> > mp;

  rep(i, M){
    int p, y;
    cin >> p >> y;
    mp[p].push_back(make_pair(y, i));
  }

  vector<ipair> ans(M);

  for(pair<int, vector<ipair>> p: mp){
    int pref = p.first;
    vector<ipair> cities = p.second;
    sort(cities.begin(), cities.end());
    rep(city_order, cities.size()){
      // cout << "===" << endl;
      // cout << "city_order:" << city_order << endl;
      // cout << "pref:" << pref << endl;
      int original_idx = cities[city_order].second;
      // cout << "original_idx:" << original_idx << endl;
      ans[original_idx] = make_pair(pref, city_order+1);
    }
  }

  rep(i, M){
    printf("%06d%06d\n", ans[i].first, ans[i].second);
  }

  return 0;
}
