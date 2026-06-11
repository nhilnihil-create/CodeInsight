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
  ll N;
  cin >> N;
  vector<vector<int>> A(N,vector<int>(3));
  REP(i, N){
    REP(j, 3){
      cin >> A.at(i).at(j);
    }
  }
  
  REP(i,101){
    REP(j,101){
      vector<ll> vec;
      ll MIN = INF;
      REP(k,N){
        if(A.at(k).at(2)==0){
          MIN=min(MIN,(ll)abs(i-A.at(k).at(1))+abs(j-A.at(k).at(0)));
          continue;
        }
        vec.push_back(A.at(k).at(2)+abs(i-A.at(k).at(1))+abs(j-A.at(k).at(0)));
      }
      ll H = vec.at(0);
      int flag = 0;
      for(auto x:vec){
        if(x!=H||MIN<x){
          flag=1;
        }
      }

      if(flag==0){
        cout << j << " " << i << " " << H << endl;
        return 0;
      }
    }
  }
}