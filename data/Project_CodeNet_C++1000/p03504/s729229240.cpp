#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> //tuple<ll,ll,ll>
#define pr(x) cout << x << endl;
using namespace std;

int main(){
  int n,c; cin >> n >> c;
  vector<vector<int> > bc(c,vector<int>(100001,0));
  rep(i,n){
    int s,t,a; cin >> s >> t >> a;
    a--;
    for(int j=s; j<=t; j++){
      bc[a][j]++;
    }
  }

  int ans=0;
  for(int i=1; i<=100000; i++){
    int tmp=0;
    rep(j,c){
      if(bc[j][i]) tmp++;
    }
    ans=max(ans,tmp);
  }

  cout << ans << endl;
return 0;
}
