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

const int mx=1000010;
const ll mod=1e9+7;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> pos;
  for(int l=0,r=n-1; l<r; ){
    if(s[l]==s[r]){
      l++;
      r--;
      continue;
    }
    if(s[l]=='x'){
      pos.emplace_back(r+1);
      l++;
      continue;
    }
    if(s[r]=='x'){
      pos.emplace_back(l);
      r--;
      continue;
    }
    cout << -1 << endl; return 0;
  }
  cout << pos.size() << endl;
  return 0;
}