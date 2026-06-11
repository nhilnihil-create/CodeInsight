#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int x,y,z,k;cin >> x >> y >> z >> k;
  vector<ll> a(x),b(y),c(z);
  rep(i,x) cin >> a[i];
  rep(i,y) cin >> b[i];
  rep(i,z) cin >> c[i];
  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());
  sort(c.rbegin(),c.rend());
  using tup = tuple<int,int,int>;
  using T = pair<ll,tup>;
  priority_queue<T,vector<T>> q;
  q.emplace(a[0]+b[0]+c[0],tup(0,0,0));
  map<tup,int> mp;
  rep(t,k){
    T temp = q.top();
    q.pop();
    ll& num = temp.first;
    cout << num << endl;
    int& i = get<0>(temp.second); 
    int& j = get<1>(temp.second); 
    int& l = get<2>(temp.second);
    //printf("%d %d %d\n",i,j,l); 
    if(mp[tup(i+1,j,l)] == 0 && i+1 < x) {
      q.emplace(a[i+1]+b[j]+c[l],tup(i+1,j,l));
      mp[tup(i+1,j,l)] = 1;
    }
    if(mp[tup(i,j+1,l)] == 0 && j+1 < y) {
      q.emplace(a[i]+b[j+1]+c[l],tup(i,j+1,l));
      mp[tup(i,j+1,l)] = 1;
    }
    if(mp[tup(i,j,l+1)] == 0 && l+1 < z) {
      q.emplace(a[i]+b[j]+c[l+1],tup(i,j,l+1));
      mp[tup(i,j,l+1)] = 1;
    }
  }

}