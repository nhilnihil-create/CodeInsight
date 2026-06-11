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
  int a[4];
  rep(i,4)cin>>a[i];
  sort(a,a+4);
  if(a[0]==1 && a[1]==4 && a[2]==7 && a[3]==9)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
