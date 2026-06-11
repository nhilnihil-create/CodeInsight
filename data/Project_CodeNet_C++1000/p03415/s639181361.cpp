#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--) 
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define downque(que) priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;
typedef long long ll;
typedef vector<vector<int>> Matrix;
const int MOD = 1e9 + 7;
const int MAX = 1e7;
const int INF = numeric_limits<int>::max();
//16:13

int main(){
  string c[3];
    REP(i,3){
    cin>>c[i];
  }
  string s=c[0].substr(0,1)+c[1].substr(1,1)+c[2].substr(2,1);
  cout<<s<<endl;

}