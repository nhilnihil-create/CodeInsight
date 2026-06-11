#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
    if(a*c<=b) cout<<c<<endl;
    else{
      cout<<b/a<<endl;
    }
}