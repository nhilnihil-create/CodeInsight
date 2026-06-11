#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
 
int main()
{
  string S;
  cin >> S;

  int flag = 1;
  if(S.at(0) != 'A'){
    flag = 0;
  }
  if(S.at(1) < 'a' || S.at(1) > 'z'){
    flag = 0;
  }
  int flag2 = 0;
  FOR(i,2,S.size()-1){
    if(S.at(i) == 'C' && flag2 == 0){
      flag2 = 1;
    }else if(S.at(i) == 'C' && flag2 == 1){
      flag = 0;
    }else if(S.at(i) < 'a' || S.at(i) > 'z'){
      flag = 0;
    }
  }
  if(flag2 == 0){
    flag = 0;
  }
  if(S.at(S.size()-1) < 'a' || S.at(S.size()-1) > 'z'){
    flag = 0;
  }

  if(flag == 1){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }
}