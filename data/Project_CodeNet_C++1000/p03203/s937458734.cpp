#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

/*
  let's try computer shogi
*/


struct block{
  ll x;
  ll y;
};

bool sblock(const block& left, const block& right){
  return left.x == right.x ? left.y > right.y : left.x < right.x;
}

int main(){
  ll h,w,n;
  cin >>h >> w >> n;
  vector<block> s;
  s.resize(n);
  for(ll i=0;i<n;++i){
    cin >> s[i].x >> s[i].y;
  }
  sort(s.begin(), s.end(), sblock);
  ll xmax = 1;
  ll ymax = 1;
  for(ll i=0;i<n;++i){
    cerr<<"block "<<s[i].x << " "<<s[i].y<<endl;
    cerr<<"xymax "<<xmax<<" "<<ymax<<endl;
    if(s[i].x < s[i].y){
      continue; //meaning less
    }
    // head attack
    if(xmax != s[i].x && s[i].x - xmax == s[i].y - ymax){
      cerr<<"head attack"<<endl;
      ymax = s[i].y - 1;
      xmax = s[i].x;
      continue;
    }
    if(xmax == s[i].x || s[i].x - xmax > s[i].y - ymax-1){
      cerr<<"hit"<<endl;
      cout<<s[i].x-1<<endl;
      return 0;
    }
  }
  cout<<h<<endl;
}