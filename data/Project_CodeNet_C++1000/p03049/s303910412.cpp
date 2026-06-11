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

int n;
string s[10010];
int a[10010];
signed main(){
  int ans=0;
  int A=0,B=0;
  bool flag=false;
  cin>>n;
  rep(i,n){
    cin>>s[i];
    a[i]=s[i].length();
    rep(j,a[i]-1){
      if(s[i][j]=='A' && s[i][j+1]=='B')ans++;
    }
    if(s[i][0]=='B')B++;
    if(s[i][a[i]-1]=='A')A++;
    if((s[i][0]=='B')^(s[i][a[i]-1]=='A')==1)flag=true;
  }
  ans+=min(A,B);
  if(!flag && A+B>0)ans--;
  cout<<ans<<endl;
  return 0;
}