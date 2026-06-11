#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d=max(a,max(b,c));
  int e=min(a,min(b,c));
  cout<<d-e<<endl;
}