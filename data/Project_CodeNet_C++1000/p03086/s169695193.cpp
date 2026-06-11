#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  string s;cin>>s;
  int n=s.length();
  int ma=0;
  int cnt=0;
  rep(i,n){
    if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T')cnt++;
    else cnt=0;
    chmax(ma,cnt);
  }
  cout<<ma<<endl;
  return 0;
}