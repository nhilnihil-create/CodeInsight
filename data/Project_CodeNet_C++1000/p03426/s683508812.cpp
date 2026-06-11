#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main(){
  int h, w, d, x;
  cin >> h >> w >> d;
  vector<P> ai(h*w+5);
  for(int i=0; i<h; ++i) for(int j=0; j<w; ++j){
    cin >> x;
    ai[x] = make_pair(i,j);
  }
  
  int dig[h*w+5];
  for(int i=1; i<=h*w; ++i){
    if(i <= d) dig[i] = 0;
    else{
      int mag = abs(ai[i].first - ai[i-d].first) + abs(ai[i].second - ai[i-d].second);
      dig[i] = dig[i-d] + mag;
    }
  }
  int q, l, r;
  cin >> q;
  for(int i=0; i<q; ++i){
    cin >> l >> r;
    cout << dig[r] - dig[l] << endl;
  }
}