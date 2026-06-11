#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  int a[4];
  rep(i,4)cin >> a[i];
  if(a[0]+a[1] > a[2]+a[3])cout << "Left" << endl;
  else if(a[0]+a[1] == a[2]+a[3])cout << "Balanced" << endl;
  else cout << "Right" << endl;




  return 0;
}