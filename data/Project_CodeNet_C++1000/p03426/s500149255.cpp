#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;

int main(){
  long long h, w, d, q;
  cin >> h >> w >> d;
  map<int, P> mp;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int a;
      cin >> a;
      mp[a] = P(i, j);
    }
  }
  cin >> q;
  long long cost[100000];
  for(int i=1;i<=d;i++){
    cost[i]=0;
    for(int j=1;i+d*j<=h*w;j++){
      int cur=i+j*d;
      int prev=i+(j-1)*d;
      P p_cur = mp[cur];
      P p_prev = mp[prev];
      cost[cur] += cost[prev] + abs(p_cur.first-p_prev.first)+abs(p_cur.second-p_prev.second);
    }
  }
  for(int i=0;i<q;i++){
    int l, r;
    cin >> l >> r;
    cout << cost[r] - cost[l] << endl;
  }
}

