#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;++i)
int main(){int n,a=0;cin>>n;vector<string>g(n),h(n);r(i,n)cin>>g[i];r(i,n){r(j,n)h[(j+i)%n]=g[j];int f=1;r(p,n){r(q,p){if(h[p][q]!=h[q][p])f=0;}}if(f)a+=n;}cout<<a<<endl;return 0;}