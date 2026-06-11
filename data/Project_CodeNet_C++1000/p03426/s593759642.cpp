#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)

int a[310][310];
int s[100100];
// C[i] := 数 i がどこにあるか(h,w)を記録する
pair<int,int> C[100100];

int main(){
  int H, W, D; cin >> H >> W >> D;
  rep(h,H) rep(w,W) {
    cin >> a[h][w];
    a[h][w]--;
    C[a[h][w]] = make_pair(h,w);
  }

  // s[i+k*D] - s[i] で 「i から始まる k 個の和」を求められるように定義した
  for(int i = 0; i+D < H*W; i++) {
    int h = C[i].first, w = C[i].second;
    int nh = C[i+D].first, nw = C[i+D].second;
    int dh = abs(h-nh);
    int dw = abs(w-nw);
    s[i+D] = s[i] + dh + dw;
  }

  // rep(i,H*W){
  //   if(i < H*W-1) printf("%d ", s[i]);
  //   else printf("%d\n", s[i]);
  // }

  int q; cin >> q;
  while(q--){
    int l, r; cin >> l >> r;
    l--; r--;
    cout << s[r]-s[l] << endl;
  }
}
