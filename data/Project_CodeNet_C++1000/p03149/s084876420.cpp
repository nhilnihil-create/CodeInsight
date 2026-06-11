#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;


int main(){  
  vector<int> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a.begin(),a.end());
  if(a[0]==1 && a[1]==4 && a[2]==7 && a[3]==9){ cout << "YES" << endl; return 0; }
  cout << "NO" << endl;
  return 0;
}