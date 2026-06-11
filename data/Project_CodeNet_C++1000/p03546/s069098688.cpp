#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
typedef pair<ll, ll> P;
//const ll INF=1LL<<60;

const int INF=100000;
int c[11][11];
int main() {
  int h,w;
	cin>>h>>w;
	rep(i,10)rep(j,10){
    int x;
    cin>>x;
    c[i][j]=x;
  }
  rep(k,10)rep(i,10)rep(j,10){
    chmin(c[i][j],c[i][k]+c[k][j]);
  }
  ll kotae=0;
  rep(i,h)rep(j,w){
    int start;
		cin>>start;
    if(start!=-1&&start!=1)kotae+=c[start][1];
	}
  cout<<kotae<<endl;
  return 0;
}
  