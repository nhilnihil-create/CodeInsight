#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()   //reverse
#define strall(v) (v).cbegin(),(v).cend() //const_itterator
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int INF = 1e9+5;

int main(){
  ll x,y;cin >> x >> y;
  ll lim = x;
  ll len = 0;
  if(lim == y) {
    cout << 1 << endl;
    return 0;
  }
  while(lim <= y){
    len++;
    lim*=2;
  }
  cout << len << endl;
}