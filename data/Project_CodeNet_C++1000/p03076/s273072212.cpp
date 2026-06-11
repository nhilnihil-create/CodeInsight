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
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;

  int a = A/10;
  int b = B/10;
  int c = C/10;
  int d = D/10;
  int e = E/10;
  vector<int> x(5);

  x.at(0) = A%10;
  x.at(1) = B%10;
  x.at(2) = C%10;
  x.at(3) = D%10;
  x.at(4) = E%10;

  
  sort(ALL(x));
  int cnt=0;
  int flag = 0;
  REP(i,5){
    if(x.at(i)!=0&&flag==0){
      flag = 1;
      cnt+=x.at(i);
      continue;
    }else if(x.at(i)!=0){
      cnt+=10;
    }
  }
  cout << (a+b+c+d+e)*10+cnt << endl;
}