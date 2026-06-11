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

const int MOD=1000000007;
int INF=100100100100100;
int g[4];
signed main(){
  rep(i,3){
    int a,b;cin>>a>>b;a--;b--;
    g[a]++,g[b]++;
  }
  if((g[0]*g[1]*g[2]*g[3])%2==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
