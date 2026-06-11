#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int n;
  string a,b,c;
  cin>>n>>a>>b>>c;

  int ans=0;
  REP(i,n){
    if(a[i]==b[i]&&b[i]==c[i]) continue;
    else if(a[i]==b[i]||b[i]==c[i]||c[i]==a[i]) ans++;
    else ans+=2; 
  }

  cout<<ans<<endl;

  return 0;
}