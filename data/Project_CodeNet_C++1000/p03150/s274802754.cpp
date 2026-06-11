#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  string S;
  cin >> S;

  if(S.substr(0,7)=="keyence"||(S.substr(0,6)=="keyenc"&&S.substr(S.size()-1)=="e")||(S.substr(0,5)=="keyen"&&S.substr(S.size()-2)=="ce")||(S.substr(0,4)=="keye"&&S.substr(S.size()-3)=="nce")||(S.substr(0,3)=="key"&&S.substr(S.size()-4)=="ence")||(S.substr(0,2)=="ke"&&S.substr(S.size()-5)=="yence")||(S.substr(0,1)=="k"&&S.substr(S.size()-6)=="eyence")||S.substr(S.size()-7)=="keyence"){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}