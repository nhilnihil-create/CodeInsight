#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  int h, w, i, j, d, q, l, r, a;

  vector<pair<int,int> > b;
  vector<int> c;

  cin >> h >> w >> d;
  b.resize(h*w+1,{-1,-1});
  c.resize(h*w+1,-1);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin >> a;
      b[a] = {i,j};
    }
  }
  for(i=0;i<d;i++){
    j = i;
    c[j] = 0;
    j += d;
    while(j<=h*w){
      c[j] = c[j-d] + abs(b[j].first-b[j-d].first) + abs(b[j].second-b[j-d].second);
      j += d;
    }
  }

  cin >> q;
  for(i=0;i<q;i++){
    cin >> l >> r;
    cout << c[r] - c[l] << endl;
  }

  return 0;
}
