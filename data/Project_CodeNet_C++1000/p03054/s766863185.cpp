#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> //tuple<ll,ll,ll>
#define pr(x) cout << x << endl;
using namespace std;

int main(){
  int h,w,n; cin >> h >> w >> n;
  int sr,sc; cin >> sr >> sc;
  string s,t; cin >> s >> t;
  int l,r;
  l=1;
  r=h;
  for(int i=n-1; i>=0; i--){
    if(l>r){
      cout << "NO" << endl;
      return 0;
    }
    if(t[i]=='D') l=max(l-1,1);
    if(t[i]=='U') r=min(r+1,h);
    if(s[i]=='D') r--;
    if(s[i]=='U') l++;
  }
  if(l>sr || sr>r){
    cout << "NO" << endl;
    return 0;
  }

  l=1;
  r=w;
  for(int i=n-1; i>=0; i--){
    if(l>r){
      cout << "NO" << endl;
      return 0;
    }
    if(t[i]=='R') l=max(l-1,1);
    if(t[i]=='L') r=min(r+1,w);
    if(s[i]=='R') r--;
    if(s[i]=='L') l++;
  }
  if(l>sc || sc>r){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
return 0;
}
