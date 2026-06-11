#include<bits/stdc++.h>
#define INF 9223372036854775807LL
#define inf 1000000007
#define SYOU(x) setprecision(x+1)
#define lol long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
lol abs(lol x,lol y){return(x>y?x-y:y-x);}
lol max(lol x,lol y){if(x>y)return x;return y;}
lol min(lol x,lol y){if(x<y)return x;return y;}
int han[100010];
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  int ans=0;
  cin >>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='o') ans++;
  }
  if(ans+15-s.size()>=8) cout <<"YES\n";
  else cout <<"NO\n";
  return (0);
}
