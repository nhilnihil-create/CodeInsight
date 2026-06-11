#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  vector<pair<int,int>> p(m);
  rep(i,m){
    cin >> a.at(i) >> b.at(i);
    p.at(i)=make_pair(b.at(i),a.at(i));
  }
  sort(all(p));
  int t,c;
  t=-1;
  rep(i,m){
    if(t<=p.at(i).second){
      c++;
      t=p.at(i).first;
    }
  }
  cout << c << endl;
}
  