#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,a,b;cin>>n>>a>>b;
  int p1=0,p2=0,p3=0;
  rep(i,n){
    int t;cin>>t;
    if(t<=a)p1++;
    else if(t<=b)p2++;
    else p3++;
  }

  cout<<min({p1, p2, p3});

  return 0;
}