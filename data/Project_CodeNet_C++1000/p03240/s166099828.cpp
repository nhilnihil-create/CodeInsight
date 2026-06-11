#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int (i) = 0;(i) < (n);(i)++)

#define maxn 110

int n;
int x[maxn],y[maxn],h[maxn];

void read(){
  cin >> n;
  REP(i,n)cin >> x[i] >> y[i] >> h[i];
}

int get_cand(int cx,int cy){
  REP(i,n){
    if(h[i] > 0){
      return h[i] + abs(x[i] - cx) + abs(y[i] - cy);
    }
  }
}

bool valid(int cx,int cy,int H,int i){
  return max(H - abs(cx - x[i]) - abs(cy - y[i]),0) == h[i];
}

bool solve(int cx,int cy){
  int H = get_cand(cx,cy);
  REP(i,n) if(!valid(cx,cy,H,i)) return false;
  cout << cx << ' ' << cy << ' ' << H << '\n';
  return true;
}

int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);
  read();

  for(int cx = 0;cx <= 100;cx++){
    for(int cy = 0;cy <= 100;cy++){
      if(solve(cx,cy)) return 0;
    }
  }

}
