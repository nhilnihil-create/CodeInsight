#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<P>data(m);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    data[i].first = b;
    data[i].second = a;
  }
  sort(data.begin(),data.end());
  int ans = 1;
  int top = data[0].first;
  rep(i,m){
    if(data[i].second >= top){
      ans++;
      top = data[i].first;
    }
  }
  cout << ans << endl;
}