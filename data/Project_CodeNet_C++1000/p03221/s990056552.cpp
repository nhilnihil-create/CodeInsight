#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, m;
  cin >> n >> m;
  vector<P> p[n];
  for(int i=0; i<m; i++){
    int x, y;
    cin >> x >> y;
    x--;
    p[x].push_back(make_pair(y, i));
  }
  vector<P> ans(m);
  for(int i=0; i<n; i++){
    if(p[i].size()==0) continue;
    sort(p[i].begin(), p[i].end());
    for(int j=0; j<p[i].size(); j++){
      ans[p[i][j].second] = make_pair(i+1, j+1);
    }
  }
  for(int i=0; i<m; i++){
    int cty, ord;
    cty = ans[i].first;
    ord = ans[i].second;
    stringstream ss;
    ss << setw(6) << setfill('0') << cty;
    ss << setw(6) << ord;

    cout << ss.str() << endl;
  }
  return 0;
}
