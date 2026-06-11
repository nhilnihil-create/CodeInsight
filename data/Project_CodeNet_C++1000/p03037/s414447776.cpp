#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,m,i,lmax,rmin,l,r;
  cin >> n >> m;
  cin >> lmax >> rmin;
  for(i=1;i<m;i++){
    cin >> l >> r;
    lmax=max(lmax,l);
    rmin=min(rmin,r);
  }
  
  cout << max(rmin-lmax+1,0) << endl;
}