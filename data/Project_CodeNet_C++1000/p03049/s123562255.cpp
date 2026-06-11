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
  int n;
  cin >> n;
  int ans = 0;
  int acnt = 0;
  int bcnt = 0;
  int dcnt = 0;
  rep(i,n){
    string s;
    cin >> s;
    if(s[0]=='B') bcnt++;
    if(s.back()=='A') acnt++;
    if(s[0]=='B' && s.back()=='A') dcnt++;
    string find_word = "AB";
    auto pos = s.find(find_word);
    while(pos != std::string::npos){
      ans++;
      pos = s.find(find_word, pos + find_word.length());
    }
  }
  ans += min(acnt, bcnt);
  if(acnt==bcnt && acnt==dcnt && acnt!=0) ans--;
  cout << ans << endl;
  return 0;
}