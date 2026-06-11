#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,h,w,a,b;  
string s,t;
bool g[15][15];

int main() {
  cin >> n >> h >> w;
  int ans=0;
  rep(i,n){
  cin >> a >> b;
  if(a/h>=1 && b/w>=1) ans+=min(a/h,b/w);
  }
  cout << ans << endl;
}