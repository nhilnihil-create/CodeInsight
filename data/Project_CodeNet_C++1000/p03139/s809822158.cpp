#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int n,a,b;cin>>n>>a>>b;
  cout<<min(a,b)<<" "<<max((int)0,a+b-n)<<endl;
  return 0;
}
