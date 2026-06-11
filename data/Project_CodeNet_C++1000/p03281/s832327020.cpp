#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


static int cntdiv[210];

void cntdivisors(int n){
 //int div[n];
  cntdiv[0] = 0;
  for(int i = 1; i <= n; i++ ){
    cntdiv[i] = 1;
  }

  for(int i = 2; i <= n; ++i){
    int j = i;
    while(j <= n){
      ++cntdiv[j];
      j = j + i;
    }
  }
}

int main(){
  int n;
  cin >> n;

  cntdivisors(201);
  int cnt = 0;


  REP(i,n+1){
    if (i % 2 != 0 && cntdiv[i] == 8) ++cnt;
  }
  cout << cnt << endl;

  return 0;
}
