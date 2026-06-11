#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  map<int,int> m1,m2;
  
  int v;
  rep(i,n){
    cin>>v;
    if(i%2==0) m1[v]++;
    else m2[v]++;
  }
  
  int a=0,b=0,c=0,d=0,an,bn,cn,dn;
  for(auto x:m1){
    if(x.second>a){
      b=a;
      a=x.second;
      an=x.first;
    }
    else if(x.second>b){
      b=x.second;
      bn=x.first;
    }
  }
  for(auto x:m2){
    if(x.second>c){
      d=c;
      c=x.second;
      cn=x.first;
    }
    else if(x.second>d){
      d=x.second;
      dn=x.first;
    }
  }
  
  if(an!=cn) cout<<n-a-c<<endl;
  else cout<<n-max(a+d,b+c)<<endl;

  return 0;
}
