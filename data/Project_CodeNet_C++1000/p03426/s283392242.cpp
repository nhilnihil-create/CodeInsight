#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int h, w, d;
  cin >> h >> w >> d;
  vector<P> a(h*w);
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      int b;
      cin >> b;
      b--;
      a[b] = make_pair(i, j);
    }
  }
  vector<int> s(h*w);
  for(int i=0; i<d; i++){
    s[i] = 0;
  }
  for(int i=d; i<h*w; i++){
    int dx = abs(a[i].first  - a[i-d].first );
    int dy = abs(a[i].second - a[i-d].second);
    s[i] = s[i-d] + dx + dy;
  }
  int q; cin >> q;
  for(int i=0; i<q; i++){
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout << s[r] - s[l] << endl;
  }
  return 0;
}
