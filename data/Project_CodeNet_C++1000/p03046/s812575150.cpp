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

const int mx=100010;
const ll mod=1e9+7;


int main() {
  int m,k; cin >> m >> k;
  int n = pow(2,m);
  if(k==0){ rep(i,n){ cout << i << " " << i << " "; } cout << endl; return 0; }
  if(k>=n || (m==1&&k==1)){cout<<-1<<endl; return 0;}
  
  rep(i,n)if(i!=k){
    cout << i << " ";
  }
  cout << k << " ";
  for(int i=n-1; i>=0; i--)if(i!=k){
    cout << i << " ";
  }
  cout << k << endl; 
  return 0;
}
