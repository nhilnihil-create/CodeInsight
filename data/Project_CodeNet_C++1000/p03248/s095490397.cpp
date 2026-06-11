#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
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


int main(){
  string s;
  cin >> s;
  int n = s.size();
  if(s[0]=='0' || s[n-1]== '1'){ cout << -1 << endl; return 0; }
  rep(i,n/2){
    if(s[i]!=s[n-2-i]){ cout << -1 << endl; return 0; }
  }

  s[n-1] = '1';
  vector<P> a;
  int cnt = 0;
  REP(i,1,n){
    if(s[i]=='1'){
      for(; cnt<i; cnt++){
        a.emplace_back(i,cnt);
      }
    }
  }
  for(auto it:a){ cout << it.F+1 << " " << it.S+1 << endl; }
  return 0;
}