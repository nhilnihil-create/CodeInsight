#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int x[N], y[N], d[N];

int main(){
  ios_base::sync_with_stdio();
  cin.tie(); cout.tie();
  int h, w, D;
  cin >> h >> w >> D;
  for(int i=0;i<h;i++){
	for(int j=0;j<w;j++){
	  int t;
      cin >> t;
      x[t] = i;
      y[t] = j;
    }
  }
  for(int i = D+1; i<=h*w; i++){
    d[i] = d[i-D] + abs(x[i]-x[i-D]) + abs(y[i]-y[i-D]);
  }
  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;
    cout << d[r]-d[l] << '\n';
  }return 0;
}