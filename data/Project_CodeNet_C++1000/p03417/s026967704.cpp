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
  ll n,m;
  ll res=0;
 cin >> n >> m; 
  if(n==1 && m==1) res = 1;
  else if(n==1 && m!=1) res=m-2;
  else if(n!=1 && m==1) res=n-2;
  else res=(ll)((n-2)*(m-2));
  cout << res <<endl;
}