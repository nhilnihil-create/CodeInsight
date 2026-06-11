#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int m;
  m=max({a,b,c});
  cout<<m*10+a+b+c-m<<endl;



  return 0;
}
