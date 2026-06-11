#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define fix(n) cout<<fixed<<setprecision(n)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
using namespace std;
typedef long long ll;
const ll mod=1000000007;
double pi=3.1415926535;

int main(){
  int n,ans=0;
  string a,b,c;
  cin>>n>>a>>b>>c;
  
  rep(i,0,n){
    if(a[i]!=b[i] && b[i]!=c[i] && c[i]!=a[i]) ans+=2;
    else if(a[i]==b[i] && b[i]!=c[i]) ans++;
    else if(a[i]!=b[i] && b[i]==c[i]) ans++;
    else if(a[i]==c[i] && b[i]!=c[i]) ans++;
  }
  co(ans);
  
  return 0;
}