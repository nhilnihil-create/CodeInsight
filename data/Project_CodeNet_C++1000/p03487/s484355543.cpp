#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main(){
  int n;
  cin >>n;
  int a[n+1];
  rep(i,n)cin >>a[i];
  sort(a,a+n);
  a[n]=0;
  int ans=0;
  int p=1;
  rep(i,n){
    if(a[i]==a[i+1]){p++;}
    else{
      if(a[i]<p){ans+=p-a[i];}else
      if(a[i]>p){ans+=p;}
      p=1;
    }
  }

  cout  << ans << endl; 
}