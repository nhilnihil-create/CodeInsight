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
  string s;
  cin >> s;
  int n = s.size();
  if(s.substr(0,7)=="keyence"){ cout << "YES" << endl; return 0; }
  if(s.substr(0,6)=="keyenc" && s.substr(n-1)=="e"){ cout << "YES" << endl; return 0; }
  if(s.substr(0,5)=="keyen" && s.substr(n-2)=="ce"){ cout << "YES" << endl; return 0; }
  if(s.substr(0,4)=="keye" && s.substr(n-3)=="nce"){ cout << "YES" << endl; return 0; }
  if(s.substr(0,3)=="key" && s.substr(n-4)=="ence"){ cout << "YES" << endl; return 0; }
  if(s.substr(0,2)=="ke" && s.substr(n-5)=="yence"){ cout << "YES" << endl; return 0; }
  if(s.substr(0,1)=="k" && s.substr(n-6)=="eyence"){ cout << "YES" << endl; return 0; }
  if(s.substr(n-7)=="keyence"){ cout << "YES" << endl; return 0; }


  cout << "NO" << endl;
  return 0;
}