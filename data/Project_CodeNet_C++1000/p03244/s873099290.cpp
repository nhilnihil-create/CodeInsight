#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int n; cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  
  unordered_map<int,int> mape, mapo;
  
  rep(i, n/2) {
    mape[v[2*i]]++;
    mapo[v[2*i+1]]++;
  }

  
  vector<pair<int,int>> vpe(0), vpo(0);
  for(auto p : mape) vpe.push_back(make_pair(p.second,p.first));
  for(auto p : mapo) vpo.push_back(make_pair(p.second,p.first));
  
  sort(all(vpe)); reverse(all(vpe));
  sort(all(vpo)); reverse(all(vpo));
  
  if(vpe[0].second != vpo[0].second) cout << n-vpe[0].first-vpo[0].first << endl;
  else if(vpe[0].first+vpo[1].first >= vpo[0].first+vpe[1].first)
                          cout << n-(vpe[0].first+vpo[1].first) << endl;
  else cout << n-(vpe[1].first+vpo[0].first) << endl;
}
