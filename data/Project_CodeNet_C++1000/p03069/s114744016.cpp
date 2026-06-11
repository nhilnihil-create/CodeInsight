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
  string S;
  cin >> S;

  vector<int> w(N);
  int wsum=0;
  vector<int> b(N);
  int bsum=0;
  REP(i,N){
    if(S.at(i)=='.'){
      wsum++;
      w[i]=wsum;
    }
  }
  REPR(i,N-1){
    if(S.at(i)=='#'){
      bsum++;
      b[i]=bsum;
    }
  }

  int MIN = INF;
  REP(i,N+1){
    if(i==0){
      MIN=min(MIN,N-i-b[i]);
    }else if(i==N){
      MIN=min(MIN,i-w[i-1]);
    }else{
      MIN=min(MIN,N-i-b[i]+i-w[i-1]);
    }
  }

  cout << MIN << endl;
}