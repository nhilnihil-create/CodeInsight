#include <bits/stdc++.h>
#define rep(i,s,n) for (int i=s;i<n;++i)
#define drep(i,s,n) for (int i=n;i>=s;--i)
#define all(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define print(x) cout<<(x)<<endl
using namespace std;
typedef long long ll;

int gcd(int a,int b)
{if (a%b == 0) return(b);
 else          return(gcd(b,a%b));}
int lcm(int a,int b)
{return a*b/gcd(a,b);}
void printv(vector<auto> v) {cout<<'[';rep(i,0,v.size()){cout<<v[i]<<',';}cout<<']'<<endl;}
void printvv(vector<vector<auto>> vv)
{
  cout<<'['<<endl;
  rep(q,0,vv.size()){cout<<'[';rep(p,0,vv.at(q).size())cout<<vv.at(q).at(p)<<',';cout <<']'<<endl;}
  cout<<']'<<endl;
}
void solve(); int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}
int step_x[] = {-1,0,0,1};
int step_y[] = {0,-1,1,0};
//------------------------------------------------------------
ll x,y,ans=0,tmpans=0;

void solve() {
  cin>>x>>y;

  // rep(i,x,round(y/2)+1)
  // {
    ll n=x;
    tmpans=1;
    while(1)
    {
      if(n*2<=y)
      {
        tmpans++;
        n = n*2;
      }
      else {break;}
    }

  //   ans = max(ans, tmpans);
  // }

  print(tmpans);  return;
}
