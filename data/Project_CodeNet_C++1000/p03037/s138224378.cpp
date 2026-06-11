#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int N,M;cin>>N>>M;
  int Lmax=0,Rmin=10000000;
  
  int L,R;
  rep(i,M){
    cin>>L>>R;
    Lmax=max(Lmax,L);
    Rmin=min(Rmin,R);
  }
  
  if(Rmin-Lmax+1<1) cout << 0 << endl;
  else cout << Rmin-Lmax+1 << endl;
}
