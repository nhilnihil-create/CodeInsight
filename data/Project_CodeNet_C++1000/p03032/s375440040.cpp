#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long mod=1e9+7;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> vn(N);
  REP(n,N) cin >> vn.at(n);

  int ans = 0;
  REP(i,min({N,K})+1){
    vector<int> vec(i);
    REP(j,i+1){
      int A = j;
      int B = i-j;
      int cnt = 0;
      REP(aa,A){
        vec.at(cnt) = vn.at(aa);
        cnt+=1;
      }
      REP(bb,B){
        vec.at(cnt) = vn.at(N-1-bb);
        cnt +=1;
      }

      sort(vec.begin(),vec.end());

      REP(k,min({K-i, i})){
        if(vec.at(k) < 0) vec.at(k) = 0;
      }

      int tmp = accumulate(vec.begin(),vec.end(), 0);
      ans = max({ans,tmp});
    }
  }
  cout << ans << endl;
}