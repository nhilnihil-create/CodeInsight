#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int n;cin>>n;
  string s;cin>>s;
  int sum=0;
  int ans=0;
  rep(i,n){
    if(s[i]=='#')sum++;
  }
  ans=sum;
  for(int i=n-1;i>=0;i--){
    if(s[i]=='#')sum--;
    else sum++;
    ans=min(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}