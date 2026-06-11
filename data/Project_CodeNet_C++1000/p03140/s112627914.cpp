#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n;
  string a,b,c;
  cin>>n;
  cin>>a;
  cin>>b;
  cin>>c;
  for(i=0;i<n;i++){
    if(a[i]==b[i] && b[i]==c[i])continue;
    if(a[i]==b[i] || b[i]==c[i] || c[i]==a[i])cnt++;
    else cnt+=2;
  }
  cout<<cnt;
}