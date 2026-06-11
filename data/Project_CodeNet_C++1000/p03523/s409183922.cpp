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
#include<memory.h>

using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

string s;

int main(){
  bool flag=false;
  cin >> s;
  if(s.size()>=10){
    cout << "NO" << endl;
    return 0;
  }
  int n = (int)s.size()+1;
  for (int bit = 0; bit < (1<<n); ++bit){
    string temp;
    temp.clear();
    for (int i = 0; i < n; ++i) {
      if (bit & (1<<i)) {
        temp.push_back('A');
        if(i==n-1)break;
      }
      if(i<s.size())temp.push_back(s[i]);
    }
    if(temp=="AKIHABARA")flag=true;
  }
  if(flag)cout << "YES" << endl;
  else cout << "NO" << endl;
return 0;}