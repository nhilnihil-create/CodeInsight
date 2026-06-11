
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n,q;
string s;
vector<char> t,d;


bool g(int m){
  m--;
  rep(i,q){
    if(s[m]==t[i]){
      if(d[i]=='L') m--;
      else m++;
    }
    if(m<0||m>n) return true;
  }
  return false;
}


int f(){
  int l=-1,r=n;
  while(r-l>1){
    int m=(r+l)/2;
    if(g(m)) l=m;
    else r=m;
  }

  if(g(r)) return r;

  return l;
}
  

int main(){
  cin>>n>>q;
  cin>>s;
  rep(i,q){
    char a,b;
    cin>>a>>b;
    t.PB(a); 
    d.PB(b);
  }

  int l=f();
  reverse(all(s));
  rep(i,q){
    if(d[i]=='L') d[i]='R';
    else d[i]='L';
  }
  int r=f();

  cout<<min(n,n-l-r)<<endl;
}
