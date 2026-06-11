#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bitset>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef long long LL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define SORTG(c) sort((c).begin(),(c).end(),greater<auto>())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define REP(i,n)  for(int i=0; i<(n); i++)

//constant
//--------------------------------------------
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const LL MOD = 1e9+7; 
int main(){
  string s;
  vector<pair<char, int>> cnt(26);
  vector<bool> ans(26);
  char c = 'a';
  REP(i, 26){
    cnt[i]=MP(c, 0);
    c++;
  }
  cin >> s;
  LL l = s.size();
  REP(i, l){
    char a = s[i];
    REP(j,26){
      if(cnt[j].first==a){
        cnt[j].second++;
        break;
      }
    }
  }
  vector<char> d, v(l, 'A');
  if(s[0]!='z'){
    ans[0] = true;
    v[0]=s[0]+1;
  }
  else ans[0]=false;
  d.push_back(s[0]);
  FOR(i, 1, l){
    int n = d.size();
    bool f = false;
    if(s[i]!='z'){
      for(char j=s[i]+1; j<='z'; j++){
        bool l = true;
        REP(k, n){
          if(d[k]==j){
            l=false;
            break;
          }
        }
        if(l){
          v[i]=j;
          f=true;
          break;
        }
      }
    }
    if(f){
      ans[i]=true;
    }else ans[i]=false;
    d.push_back(s[i]);
  }
  bool flg = false;
  REP(i, 26){
    if(cnt[i].second==0){
      flg=true;
      s+=cnt[i].first;
      break;
    }
  }
  int e = 27;
  if(flg==false){
    for(int i=l-1; i>=0; i--){
      if(ans[i]==true){
        s[i]=v[i];
        e = i;
        string t = s.substr(0,e+1);
        s=t;
        flg = true;
        break;
      }
    }
  }
  if(flg) cout << s << endl;
  else cout << -1 << endl;
}