
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


bool f(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a<b) return false;
  if(b>d) return false;
  if(c>=b) return true;
  if(c<b+(a%__gcd(b,d))-__gcd(b,d)) return false;

  return true;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    if(f())
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }

}
