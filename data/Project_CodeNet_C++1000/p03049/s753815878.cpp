#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;
signed main(){
  int n;
  cin >> n;
  int BA = 0;
  int A = 0;
  int B = 0;
  int ans = 0;
  rep(i,n){
    string s;
    cin >> s;
    rep(i,s.size()-1){
      if(s[i] == 'A' && s[i+1] == 'B') ans++;
    }
    if(s[0] == 'B' && s[s.size()-1] == 'A') BA++;
    else if(s[0] == 'B') B++;
    else if(s[s.size()-1] == 'A') A++;
  }
  //cout << A << " " <<  B << " " << BA << endl;
  if(BA > 0){
    ans += BA-1; 
      if(A > 0) ans++;
      A--;
      if(B > 0) ans++;
      B--;
  }
  while(A > 0 && B > 0){
    ans++;
    A--;
    B--;
  }
  cout << ans << endl;
} 