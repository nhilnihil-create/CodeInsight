#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
  int n,m; cin >> n >> m;
  vector<P> is;
  rep(i,m){
    int a,b; cin >> a >> b;
    is.emplace_back(a,b);
  }

  sort(all(is));
  int ans=1;
  //int l=is[0].first;
  int r=is[0].second;
  rep(i,m-1){
    if(is[i+1].first>=r){
      ans++;
      //l=is[i+1].first;
      r=is[i+1].second;
    }
    r=min(r,is[i+1].second);
  }
  cout << ans << endl;
return 0;
}