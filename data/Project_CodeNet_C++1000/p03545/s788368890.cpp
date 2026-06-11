#include <bits/stdc++.h>
using namespace std;

// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)

#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define F         first
#define S         second

template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if (f) Out(y); else Out(n); }

using int64 = long long;

signed main() {

    // ⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎



  string s;
  cin >> s;
  
  for(int i = 0; i < (1 << 3); i++){  
    int cur = s[0] - '0'; 

    string ans;
    ans += s[0];   

    for(int j = 1; j < 4; j++){
      if((i >> (j - 1)) & 1){
        cur += s[j] - '0';
        ans += "+";
        ans += s[j];
      } else {
        cur -= s[j] - '0';
        ans += "-";
        ans += s[j];
      }
    }
    if(cur == 7) {
      cout << ans << "=7" << endl;
          return(0);
    }
  }

    
 
}

