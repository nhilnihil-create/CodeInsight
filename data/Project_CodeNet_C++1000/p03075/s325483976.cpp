#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i <= n; i++)
#define ll long long
using namespace std;

int main() {
  int a,b,c,d,e,k;
  cin>>a>>b>>c>>d>>e>>k;
  if(a<e){
    if(e-a<=k) cout<<"Yay!"<<endl;
    else cout<<":("<<endl;
  }
  else{
    if(a-e<=k)cout<<"Yey!"<<endl;
    else cout<<":("<<endl;
  }
}
  