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
int a[100010];
int b[100010];
ivec pos;
//ivec neg;
int neg;
signed main(){
  int n;cin>>n;
  int sum=0;
  int ans=0;
  rep(i,n)cin>>a[i];
  rep(i,n){
    cin>>b[i];
    sum+=a[i]-b[i];
    if(a[i]-b[i]<0){
      neg+=b[i]-a[i];
      ans++;
    }
    else if(a[i]-b[i]>0)pos.pb(a[i]-b[i]);
  }
  if(sum<0){
    cout<<-1<<endl;
    return 0;
  }
  if(neg==0){
    cout<<0<<endl;
    return 0;
  }
  sort(all(pos),greater<int>());
  int ima=0;
  for(ima=0;neg>0;ima++){
    neg-=pos[ima];
  }
  ans+=ima;
    
  cout<<ans<<endl;
  return 0;
}
