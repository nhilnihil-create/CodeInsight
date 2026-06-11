#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,c;
  cin >> n >> c;
  vvint chan(30,vint(200000));
  rep(i,0,n){
    int s,t,c;
    cin >> s >> t >> c;
    s--;t--;c--;
    chan[c][s]++;
    chan[c][t]++;
    if(chan[c][s] == 2) chan[c][s] = 0;
    if(chan[c][s] == 2) chan[c][s] = 0;
  }
  vbool judge(c);
  int ans = 0;
  rep(i,0,200000){
    int tmp = 0;
    rep(m,0,c){
      if(chan[m][i] == 1){
        if(judge[m] == 0){
          tmp++;
          judge[m] = 1;
        }
        else{
          tmp++;
          judge[m] = 0;
        }
      }
      else if(judge[m] == 1) tmp++;
    }
    ans = max(ans,tmp);
  }
  cout << ans << endl;
}