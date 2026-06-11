#include<bits/stdc++.h>
#define INF 2147483647
#define inf 1000000007
#define SYOU(x) setprecision(x)
#define abs(x,y) (max(x,y)-min(x,y))
#define lol long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
long long i[3000000];
bool o;
bool ans[5];
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a,b,c,d=inf,e=0,f=0,g=0,h=0,j=0;
  string s;
  cin >>s;
  b=s.size();
  for(lol n=0;n<b-1;n++){
    if(s[n]!=s[n+1]){
      a=max(n+1,b-n-1);
      d=min(d,a);
    }
  }
  if(d==inf) d=b;
  cout <<d<<'\n';
  return (0);
}
