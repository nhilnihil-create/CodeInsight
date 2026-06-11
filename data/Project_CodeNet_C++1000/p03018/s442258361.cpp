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
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000000000009
#define int long long
using P = pair<int,int>;

signed main(){
  string s;
  cin >> s;
  int ans = 0;
  string r=regex_replace(s,regex("BC"), "X");
  //cout << r << endl;
  int acount = 0;
  rep(i,r.size()){
    if(r[i] == 'A'){
      acount++;
    }
    else if(r[i] == 'X'){
      ans += acount;
    }
    else{
      acount = 0;
    }
    //cout << acount << " " << ans << endl;
  }
  cout << ans << endl;
}