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
  char c;cin>>c;
  if(c=='A')cout<<'T'<<endl;
  if(c=='T')cout<<'A'<<endl;
  if(c=='G')cout<<'C'<<endl;
  if(c=='C')cout<<'G'<<endl;
  
  return 0;
}