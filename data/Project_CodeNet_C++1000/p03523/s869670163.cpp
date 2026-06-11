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
  string news;
  vector<string> candidates;

  FOR(i,0,1){
    FOR(j,0,1){
      FOR(k,0,1){
        FOR(l,0,1){
          string trys;
          if(i==1) trys += "A";
          trys += "KIH";
          if(j==1) trys += "A";
          trys += "B";
          if(k==1) trys += "A";
          trys += "R";
          if(l==1) trys += "A";

          candidates.PB(trys);
        }
      }
    }
  }
  

  for(auto x: candidates){
    if(s==x){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}