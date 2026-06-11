#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

int main(){
int n,ans=0;cin>>n;
vector<string> g(n),g2(n);rep(i,n)cin>>g[i];
rep(i,n){
rep(j,n)g2[(j+i)%n]=g[j];
bool f=true;
rep(p,n){rep(q,p){if(g2[p][q]!=g2[q][p]){f=false;}}}
if(f)ans += n;
}
cout<<ans<<endl;return 0;
}
