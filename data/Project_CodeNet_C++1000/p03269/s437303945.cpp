#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define rrep(i,s,e) for(int (i) = (s);(i) >= (e);(i)--)

vector<int> u;
vector<int> v;
vector<int> w;


signed main() {
  int l;cin>>l;
  int tmp = l;
  int cnt = 0;
  int cost = 1;
  while(tmp/2)
  {
    tmp/=2;
    cnt++;
    u.push_back(cnt);
    v.push_back(cnt+1);
    w.push_back(0);
    u.push_back(cnt);
    v.push_back(cnt+1);
    w.push_back(cost);
    cost *= 2;
  }
  int endN = cnt+1;
  cnt = 0;
  l -= cost;

  while(l){
    tmp = l;
    cnt = 0;
    while(tmp/2)
    {
      tmp/=2;
      cnt++;
    }
    u.push_back(cnt+1);
    v.push_back(endN);
    w.push_back(cost);
    int a=1;
    rep(i,0,cnt-1) a*=2;
    cost += a;
    l -= a;
  }

  cout << endN << " " << u.size() << endl;

  rep(i,0,u.size()-1) cout << u[i] <<" "<<v[i]<<" "<<w[i]<<endl;
}
