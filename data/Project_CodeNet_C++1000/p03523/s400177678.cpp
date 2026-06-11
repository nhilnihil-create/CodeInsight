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
  string S;
  cin >> S;

  if(S=="KIHBR"||S=="AKIHBR"||S=="KIHABR"||S=="KIHBAR"||S=="KIHBRA"||S=="AKIHABR"||S=="AKIHBAR"||S=="AKIHBRA"||S=="KIHABAR"||S=="KIHABRA"||S=="KIHBARA"||S=="AKIHABAR"||S=="AKIHABRA"||S=="AKIHBARA"||S=="KIHABARA"||S=="AKIHABARA"){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}