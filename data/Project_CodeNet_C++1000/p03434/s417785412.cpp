#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) x.begin(), x.end()
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,n) cin>>a[i];
  sort(a,a+n,greater<int>());
  int Alice=0,Bob=0;
  rep(i,n){
    if(i%2==0) Alice+=a[i];
    else Bob+=a[i];
  }
  cout<<Alice-Bob<<endl;
}