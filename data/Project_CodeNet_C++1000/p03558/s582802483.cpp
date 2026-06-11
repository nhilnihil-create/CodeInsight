#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
  ll k;
  cin >> k;
  vector<ll> v(k,-1);
  priority_queue<P,vector<P>,greater<P>> q;
  auto push = [&](ll nk,ll d){
    nk %= k;
    if(0<v[nk] && v[nk]<=d) return;
    v[nk]=d;
    q.emplace(d,nk);
  };
  push(1,1);
  while(!q.empty()){
    P p = q.top(); q.pop();
    ll d = p.first, k = p.second;
    if(k%10<9) push(k+1,d+1);
    push(k*10,d);
  }
  cout << v[0] << endl;
}