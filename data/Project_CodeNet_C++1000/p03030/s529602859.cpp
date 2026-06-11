#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

int main() {
  vector<pair<pair<string,int>,int>> r(110);
  int n;
  cin>>n;
  rep(i,n) {
    cin>>r[i].first.first>>r[i].first.second;
    r[i].first.second*=-1;
    r[i].second=i+1;
  }
  sort(r.begin(),r.begin()+n);
  rep(i,n) cout<<r[i].second<<endl;
}
