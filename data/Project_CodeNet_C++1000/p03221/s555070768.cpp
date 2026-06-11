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
ll GetDigit(ll num){
  return to_string(num).length();
}
int main()
{
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> A(M,vector<ll>(3));
  REP(i, M){
      cin >> A.at(i).at(0) >> A.at(i).at(1);
      A.at(i).at(2)=i;
  }
  sort(ALL(A));
  vector<string> B(M);
  int cnt = 1;
  REP(i,M){
    if(i!=0&&A.at(i).at(0)==A.at(i-1).at(0)){
      cnt++;
    }else if(i!=0&&A.at(i).at(0)!=A.at(i-1).at(0)){
      cnt=1;
    }
    string x;
    int y = 6-GetDigit(A.at(i).at(0));
    REP(j,y){
      x.push_back('0');
    }
    x+=to_string(A.at(i).at(0));
    int z = 6-GetDigit(cnt);
    REP(j,z){
      x.push_back('0');
    }
    x+=to_string(cnt);
    B[A.at(i).at(2)]=x;
  }

  REP(i,M){
    cout << B[i] << endl;
  }
}