#include<iostream>
#include <numeric>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> P;
int n, m, ans=0;

int main(){
  cin >> n >> m;
  vector<int> bridge(m);
  vector<P> ps(m);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    ps[i] = P(b, a);
  }
  sort(ps.begin(), ps.end());
  int cur = -100001;
  for(int i=0; i<m; i++){
    if(cur <= ps[i].second){
      ans++;
      cur = ps[i].first;
//      cout << ps[i].first << " " << ps[i].second << endl;
    }
  }
  
  cout << ans << endl;
  return 0;
}