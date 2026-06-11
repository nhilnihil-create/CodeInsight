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
  int n; cin >> n;
  vector<vector<int> > f(n);
  rep(i,n)rep(j,10){
    int tmp; cin >> tmp;
    f[i].push_back(tmp);
  }
  vector<vector<int> > p(n);
  rep(i,n)rep(j,11){
    int tmp; cin >> tmp;
    p[i].push_back(tmp);
  }

  int ans=-INF;

  int ma=pow(2,10);
  for(int i=1; i<ma; i++){
    int ti=i;
    vector<int> eigyou(10,0);
    rep(j,10){
      if(ti%2==1) eigyou[j]++;
      ti/=2;
    }
    int bnf=0;
    rep(j,n){
      int cnt=0;
      rep(k,10){
        if(f[j][k]==1 && eigyou[k]==1) cnt++;
      }
      bnf+=p[j][cnt];
    }
    ans=max(ans,bnf);
  }

  cout << ans << endl;
return 0;
}
