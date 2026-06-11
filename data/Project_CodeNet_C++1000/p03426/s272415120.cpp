#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll h,w,d;
  cin >> h >> w >> d;
  ll si = h*w / d + 1;
  vector<vector<pair<ll,ll>>> pos(d,vector<pair<ll,ll>>(si));
  //cout << 0 << endl;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      ll in;
      cin >> in;
      ll syou = in / d;
      ll mod = in % d;
      pos[mod][syou] = make_pair(i,j);
    }
  }
  //cout << 1 << endl;
  vector<vector<ll>> cost(d,vector<ll>(si));
  for(int i = 0;i < d;i++){
    cost[i][0] = 0;
    for(int j = 1;j < si;j++){
      cost[i][j] = cost[i][j - 1] + abs(pos[i][j].first - pos[i][j - 1].first) + abs(pos[i][j].second - pos[i][j - 1].second);
    }
  }
  //cout << 2 << endl;
  ll q;
  cin >> q;
  for(int i = 0;i < q;i++){
    ll l,r;
    cin >> l >> r;
    ll mod = l % d;
    //cout << mod << " " << r / d << " " << l / d << endl;
    cout << cost[mod][r / d] - cost[mod][l / d] << endl;
  }
}