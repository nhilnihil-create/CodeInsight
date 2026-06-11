#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x; cin>>n>>x;
  int min_m=2*10e5;
  int sum_m=0;
  for (int i=0; i<n; i++){
    int m; cin>>m;
    sum_m+=m;
    min_m=min(min_m,m);
  }
  x-=sum_m;
  cout<<n+x/min_m<<endl;
}