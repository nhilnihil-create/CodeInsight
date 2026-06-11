#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define REPS(i,n) for(int i=1;i<=(n);i++)
#define RREPS(i,n) for(int i=(n);i>0;i--)
#define mp make_pair
#define pb(a) push_back(a)
typedef long long ll;

int main(){
  string S;
  cin >> S;
  int cnt[3] = {};
  REP(i,S.length()){
    cnt[(int)(S[i] - 'a')]++;
  }
  int M = max(cnt[0],max(cnt[1],cnt[2]));
  int m = min(cnt[0],min(cnt[1],cnt[2]));
  if(M - m <= 1) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
