#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e6;

struct S {
  int x, y, t;  
};

map<int, bool> koma[300010];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int H, W, N;
  cin >> H >> W >> N;

  // assert(H+W < 200000);  

  int ans = H;
  vector<pair<int, int> > dat(N);  
  for ( int i = 0; i < N; i++ ) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    dat[i] = make_pair(x, y);    
    koma[y][x] = true;    
  }
  
  int path[300010];
  fill_n(path, 300010, INF);  
  {
    int x = 0, y = 0, t = 0;    
    while ( 1 ) {
      if ( x > H || y > W ) break;
      path[y] = min(path[y], x);      
      if ( !t ) {
	if ( !koma[y][x+1] ) {
	  x++;	  
	} else {
	  break;	  
	}
	t = 1;	
      } else {
	if ( !koma[y+1][x] ) {
	  y++;	  
	}
	t = 0;
      }
    }
  }

  for ( int i = 0; i < N; i++ ) {
    auto e = dat[i];
    int x = e.first, y = e.second;
    if ( path[y] < x ) ans = min(ans, x);    
  }  

  cout << ans << endl;
  
  return 0;
}
