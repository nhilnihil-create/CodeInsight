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

signed main(){
  int ans=0;
  int sa=0;
  rep(i,5){
    int x;cin>>x;
    ans+=(x+9)/10*10;
    int po=x%10;
    if(po>0)po=10-po;
    sa=max(sa,po);
  }
  ans-=sa;
  cout<<ans<<endl;
  return 0;
}
