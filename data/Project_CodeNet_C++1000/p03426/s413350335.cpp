#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w,d;
  cin >> h >> w >> d;
  vector<P>data(h*w+1);
  rep(i,0,h) rep(j,0,w){
    int a;
    cin >> a;
    data[a].first = i;data[a].second = j;
  }
  vector<int>dist(h*w+1);
  rep(i,1,d+1) dist[i] = 0;
  rep(i,d,h*w+1){
    int p = i-d;
    int vx = data[i].first,vy = data[i].second,px = data[p].first,py = data[p].second;
    dist[i] = dist[p]+abs(vx-px)+abs(vy-py);
  }
  int q;
  cin >> q;
  rep(i,0,q){
    int l,r;
    cin >> l >> r;
    cout << dist[r]-dist[l] << endl;
  }
}