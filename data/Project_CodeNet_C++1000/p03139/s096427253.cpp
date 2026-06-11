#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n,a,b;
  cin>>n>>a>>b;
  cout<<min(a,b)<<" "<<max(0,a+b-n);
}