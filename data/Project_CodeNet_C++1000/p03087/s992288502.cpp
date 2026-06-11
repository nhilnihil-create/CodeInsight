#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,q,a,b,c,i,x[100010];
string s;
int main(){
  for(cin>>n>>q>>s,i=1;i<n;++i){
    x[i+1]=x[i];
    if(s[i-1]=='A'&&s[i]=='C')x[i+1]++;
  }
  for(i=0;i<q;++i){
    cin>>a>>b;
    cout<<x[b]-x[a]<<endl;
  }
}