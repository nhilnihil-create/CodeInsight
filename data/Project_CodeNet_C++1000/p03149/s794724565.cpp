#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes(){
  cout << "YES" << endl;
  exit(0);
}

void no(){
  cout << "NO" << endl;
  exit(0);
}

int main(){
  vector<char> s(4);
  REP(i,4) cin >> s[i];
  sort(ALL(s));
  string t = "1479";
  REP(i,4){
    if(s[i]!=t[i]) no();
  }
  yes();
}