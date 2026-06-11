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
 
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

const int mx=100010;
const ll mod=1e9+7;


int main(){  
  int n;
  cin >> n;
  if(n==1){
    cout << "Hello World" << endl;
    return 0;
  }
  int a,b;
  cin >> a >> b;
  cout << a+b << endl;
  return 0;
}