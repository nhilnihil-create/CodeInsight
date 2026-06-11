#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M 1000000007
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
#define S seconnd
#define int ll
#define PB push_back

int n;
string s;
map<pair<string,string>,int> ma;
int ans=0;

void f(string t,string u,int m){
  if(m==s.size()/2){
    ma[make_pair(t,u)]++;
    return;
  }

  f(t,u+s[m],m+1);
  f(t+s[m],u,m+1);
}


void g(string t,string u,int m){
  if(m==s.size()/2){
    ans+=ma[make_pair(t,u)];
    return;
  }

  g(t,u+s[m],m+1);
  g(t+s[m],u,m+1);
}



signed main(){
  cin>>n>>s;

  string t="",u="";
  f(t,u,0);
  reverse(all(s));
  
  string a="",b="";
  g(a,b,0);

  cout<<ans<<endl;

}