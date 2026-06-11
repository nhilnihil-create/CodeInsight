#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  int N;
  cin >> N;

  vector<string> S(N);
  REP(i, N) cin >> S[i];
  
  ll B[5] = {0};
  REP(i,N){
    if(S.at(i).at(0)=='M'){
      B[0]++;
    }else if(S.at(i).at(0)=='A'){
      B[1]++;
    }else if(S.at(i).at(0)=='R'){
      B[2]++;
    }else if(S.at(i).at(0)=='C'){
      B[3]++;
    }else if(S.at(i).at(0)=='H'){
      B[4]++;
    }
  }
  ll x = B[0]*B[1]*B[2]+
  B[0]*B[1]*B[3]+
  B[0]*B[1]*B[4]+
  B[0]*B[2]*B[3]+
  B[0]*B[2]*B[4]+
  B[0]*B[3]*B[4]+
  B[1]*B[2]*B[3]+
  B[1]*B[2]*B[4]+
  B[1]*B[3]*B[4]+
  B[2]*B[3]*B[4];
  cout << x << endl;
  
}