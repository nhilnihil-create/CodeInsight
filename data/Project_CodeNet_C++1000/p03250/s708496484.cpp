#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> vec = {A, B, C};
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int S = vec[2];
  int M = vec[0]*10 + vec[1];
  cout << S + M << endl;
  
  return 0;
  
}