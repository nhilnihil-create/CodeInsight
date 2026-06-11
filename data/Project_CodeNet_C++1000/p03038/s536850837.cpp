#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<P> vt;
  for(int i=0; i<m; i++){
    int b, c;
    cin >> b >> c;
    vt.push_back(make_pair(c, b));
  }
  sort(vt.begin(), vt.end(), greater<P>());
  int k = 0;
  bool isend = false;
  for(int i=0; i<m; i++){
    if(k>=n) break;
    P p = vt[i];
    for(int j=0; j<p.second; j++){
      if(k>=n) break;
      if(a[k]>=p.first){
        isend=true;
        break;
      }
      a[k] = p.first;
      k++;
    }
    if(isend) break;
  }
  ll ans = 0;
  for(int i=0; i<n; i++){
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
