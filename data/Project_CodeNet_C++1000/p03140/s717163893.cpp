#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n;  
string s,a,b,c;

int main() {
  cin >> n >> a >> b >> c;
  int ans=0,cnt=0;
  rep(i,n){
    cnt=0;
    if(a[i]==b[i]) cnt++;
    if(b[i]==c[i]) cnt++;
    if(c[i]==a[i]) cnt++;
    if(cnt==1) ans++;
    if(cnt==0) ans+=2;
  }
  cout << ans << endl;
}