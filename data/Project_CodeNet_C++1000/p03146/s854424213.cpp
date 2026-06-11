#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int v[1000090];int re[1000090];
int main() {
  int ans=0;
  int s;cin>>s;v[0]=s;re[s]=1;
  rep(i,1000070){
    v[i]=(v[i-1]%2)?v[i-1]*3+1:v[i-1]/2;
    if(re[v[i]]==1){ ans=i+1;break;}
    re[v[i]]=1;
    cerr<<v[i]<<" ";
  }
    cout<<ans<<endl;
}