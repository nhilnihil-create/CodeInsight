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
  string S,T;
  cin >> S >> T;
  int flag2 = 0;
  vector<string> A;
  REP(i,S.size()-T.size()+1){
    int flag=0;
    REP(j,T.size()){
      if(S.at(i+j)!='?'&&S.at(i+j)!=T.at(j)){
        flag=1;
      }     
    }
    if(flag==0){
      flag2=1;
      string U=S;
      REP(j,T.size()){
        U.at(i+j)=T.at(j);
      }
      A.push_back(U);
    }
  }
  if(flag2==0){
    cout << "UNRESTORABLE" << endl;
  }else{
    REP(i,A.size()){
      REP(j,A.at(i).size()){
        if(A.at(i).at(j)=='?'){
          A.at(i).at(j)='a';
        }
      }
    }
    sort(ALL(A));
    cout << A.at(0) << endl;
  }
}