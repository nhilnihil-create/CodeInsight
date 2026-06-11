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
  string s;
  cin >> s;
  bool a = false;
  bool b = false;
  bool c = false;
  rep(i,3){
    if(s[i] == 'a') a = true;
    if(s[i] == 'b') b = true;
    if(s[i] == 'c') c = true;
  }
  if(a && b && c) cout << "Yes" << endl;
  else cout << "No" << endl;
}