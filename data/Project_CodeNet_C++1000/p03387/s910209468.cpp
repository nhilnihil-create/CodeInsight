#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
  //int a,b,c; cin >> a >> b >> c;
  //int mx = max({a,b,c});
  int a[3]; cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  //0 11 00
  //1 00
  if(a[0]%2 == a[1]%2) cout << (a[2]*3 - (a[0]+a[1]+a[2]))/2 << endl;
  else cout << ((a[2]+1)*3 - (a[0]+a[1]+a[2]))/2 << endl;
//  if( a[2]%2 == (a[0]+a[1])%2 ) cout << (a[2]*3 - (a[0]+a[1]+a[2]))/2 << endl;
  return 0;
}

/*
Ctrl+@
g++ a.cpp
./a.out
*/
