#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int a,b,c;
  cin>>a>>b>>c;
  if((a>c && c>b) || (a<c && c<b))cout<<"Yes";
  else cout<<"No";
}