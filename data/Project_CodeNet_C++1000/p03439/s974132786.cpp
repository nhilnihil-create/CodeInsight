#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);
int n;
int vec[100010];
void solve(){
  int l=0,r=n;
  cout << 0 << endl;
  string s;
  cin >> s;
  if(s[0]=='V')return;
  if(s[0]=='M')vec[0]=1;
  if(s[0]=='F')vec[0]=2;
  
  while(true){
    int c=(r+l)/2;
    cout << c << endl;
    string t;
    cin >> t;
    if(t[0]=='V')return;
    if(t[0]=='M')vec[c]=1;
    if(t[0]=='F')vec[c]=2;
    
    if((c-l)%2^vec[c]==vec[l])l=c;
    else r=c;
  }
}
  
int main(){
  cin >> n;
  int t=1;
  while(t--){
    solve();
  }
  return 0;
  
}
