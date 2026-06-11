#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,n;cin>>h>>w>>n;
  ll r,c;cin>>r>>c;
  string s,t;cin>>s>>t;
  bool fl = true;
  // right
  ll now = c;
  for(int i=0;i<n;i++){
    if(s[i] == 'R')now++;
    if(now > w)fl = false;
    if(now > 1 && t[i] == 'L')now--;
  }

  now = c;
  for(int i=0;i<n;i++){
    if(s[i] == 'L')now--;
    if(now < 1)fl = false;
    if(now < w && t[i] == 'R')now++;
  }

  now = r;
  for(int i=0;i<n;i++){
    if(s[i] == 'D')now++;
    if(now > h)fl = false;
    if(now > 1 && t[i] == 'U')now--;
  }

  now = r;
  for(int i=0;i<n;i++){
    if(s[i] == 'U')now--;
    if(now < 1)fl = false;
    if(now < h && t[i] == 'D')now++;
  }

  if(fl)cout<<"YES"<<endl;
  else cout<<"NO"<<endl; 
  return 0;
}