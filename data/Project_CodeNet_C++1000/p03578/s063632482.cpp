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
#define INF 100000000000000009
#define int long long
using P = pair<int,int>;
signed main(){
  map<int,int> IN{};
  map<int,int> OUT{};
  int n;
  cin >> n;
  rep(i,n){
    int d;
    cin >> d;
    IN[d]++;
  }
  int m;
  cin >> m;
  rep(i,m){
    int t;
    cin >> t;
    OUT[t]++;
  }
  bool flag = true;
  for(auto p: OUT){
    int key = p.first;
    int value = p.second;
    if(value > IN[key]) flag = false;
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}