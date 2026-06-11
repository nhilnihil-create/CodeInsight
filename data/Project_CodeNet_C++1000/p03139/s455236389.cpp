#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,a,b;cin>>n>>a>>b;
  cout<<min(a,b)<<' '<<max(0, -(n-a-b))<<endl;
  return 0;
}