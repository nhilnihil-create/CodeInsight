#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

bool check(pair<ll,ll> x, pair<ll,ll> y, ll ab){
  ll n = x.second+1 - x.first;
  ll a0 = x.first;
  ll b0 = y.first;

  ll lb = 0, ub = n;
  while(ub-lb>1){
    ll m = lb + (ub-lb)/2;
    double aa = (a0 + m) * (double)(b0 - m);
    double bb = (a0 + m+1) * (double)(b0 - (m+1));
    if(aa > 1e19 || (m<n && bb > 1e19)){
      return false;
    }
    ll laa = (a0 + m) * (b0 - m);
    ll lbb = (a0 + m+1) * (b0 - (m+1));

    //cout << "    " << m << " " << aa << " " << bb << endl;
    if(lbb-laa>=0) lb = m;
    else ub = m;
  }
  if(ub < n) return (a0 + lb) * (b0 - lb) < ab && (a0 + ub) * (b0 - ub) < ab;
  return (a0 + lb) * (b0 - lb) < ab;
}


bool f(ll A, ll B, ll X){
  //cout << "F: " << A << " " << B << " " << X << endl;
  vector<pair<ll,ll>> v, w;
  if(A<=X){
    if(1<=A-1) v.push_back(make_pair(1,A-1));
    if(A+1<=X+1) v.push_back(make_pair(A+1,X+1));
  }else{
    v.push_back(make_pair(1,X));
  }
  if(B<=X){
    if(X+1>=B+1) w.push_back(make_pair(X+1,B+1));
    if(B-1>=1) w.push_back(make_pair(B-1,1));
  }else{
    w.push_back(make_pair(X,1));
  }
  if(v.size() == 0 || w.size() == 0) return false;
/*
  rep(i,v.size()){
    cout << " " << v[i].first << " " << v[i].second << endl;
  }
  rep(i,w.size()){
    cout << " " << w[i].first << " " << w[i].second << endl;
  }
*/
  vector<pair<ll,ll>> vv, ww;
  int ii = 0, jj = 0;
  pair<ll,ll> x(0,0), y(0,0);
  while(true){

    if(x.first == 0){
      if(ii>=v.size()) break;
      x = v[ii];
      ii++;
    }
    if(y.first == 0){
      if(jj>=w.size()) break;
      y = w[jj];
      jj++;
    }
    ll n = x.second+1-x.first;
    ll m = y.first+1-y.second;

    if(n < m){
      vv.push_back(x);
      x.first = 0;
      ww.push_back(make_pair(y.first,y.first-(n-1)));
      y.first = y.first-n;
      if(y.first < y.second) y.first = 0;
    }
    else if(n == m){
      vv.push_back(x);
      x.first = 0;
      ww.push_back(y);
      y.first = 0;
    }
    else{
      vv.push_back(make_pair(x.first,x.first+(m-1)));
      x.first = x.first+m;
      if(x.first > x.second) x.first = 0;
      ww.push_back(y);
      y.first = 0;
    }
  }

  //rep(i,vv.size()){
  //  cout << i << " " << vv[i].first << " " << vv[i].second << " " << ww[i].first << " " << ww[i].second << endl;
  //}

  bool flg = true;
  rep(i,vv.size()){
    if(!check(vv[i],ww[i],A*B)) flg = false;
  }
  //if(flg) cout << "YES" << endl;
  //else cout << "NO" << endl;
  return flg;
}


ll solve(ll A, ll B){
  if(A>B) swap(A,B);

  ll lb = 0, ub = A*B;
  while(ub-lb>1){
    ll m = (lb+ub)/2;
    if(f(A, B, m)) lb = m;
    else ub = m;
  }

  return lb;
}


int main(){
  int Q;
  cin >> Q;

  rep(i,Q){
    ll A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;
  }
  return 0;
}
