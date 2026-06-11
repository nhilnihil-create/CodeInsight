#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int h,w; cin >> h >> w;
  vector<string> s(h); rep(i,h) cin >> s[i];
  vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};

  if(h == 1 && w == 1){
    cout << "Yes" << endl;
    return 0;
  }
  
  bool can_all = true;
  rep(i,h){
    rep(j,w){
      if(s[i][j] == '#'){
	//cout << "here" << endl;
	vector<bool> can(4,false);
	rep(k,4){	  
	  int x = i,y = j;
	  //printf("k: %d dx: %d dy: %d\n",k,x+dx[k],y+dy[k]);
	  if(x+dx[k]>=h || x+dx[k]<0 || y+dy[k]>=w || y+dy[k]<0) continue;
	  //cout << "here2" << endl;
	  x += dx[k];
	  y += dy[k];
	  if(s[x][y] == '#')  can[k] = true;
	}
	rep(k,4){
	  if(can[k]){
	    can_all = true;
	    break;
	  }
	  else can_all = false;
	}
	if(!can_all) goto rem;
      }
    }
  }
 rem:
  if(!can_all) cout << "No" << endl;
  else cout << "Yes" << endl;
  
  return 0;
}
