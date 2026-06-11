#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,m,x;
  cin >> n >> m >> x;
  int low=0;
  int high=0;
  for(int i=0;i<m;++i){
    int a;
    cin >> a;
    if(a<x) low++;
    else high++;
  }
  int ans=min(low,high);
  cout << ans << endl;
  return 0;
}
