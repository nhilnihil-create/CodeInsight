#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(void){
  string s; cin >> s;
  map<char,int> m;
  FOR(i,0,s.length()-1){
    ++m[s[i]];
  }

  FOR(i,0,25){
    if(m[(char)('a'+i)]==0){
      s += (char)('a'+i);
      cout << s << endl;
      return 0;
    }
  }

  FORD(i,25,0){
    --m[s[i]];
    int index = (int)(s[i]-'a');
    FOR(j,index+1,25){
      if(m[(char)('a'+j)]==0){
        string ans;
        FOR(k,0,i-1) {
          ans += s[k];
        }
        ans += (char)('a'+j);
        cout << ans << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
}