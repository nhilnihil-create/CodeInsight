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
  int H, W;
  cin >> H >> W;

  vector<string> A(H);
  REP(i, H) cin >> A[i];
  
  
  int x[] = {1,0,-1,0};
  int y[] = {0,1,0,-1};

  int flag = 0;
  REP(i,H){
    REP(j,W){
      if(A.at(i).at(j)=='#'){
        int flag2 = 0; 
        REP(k,4){
          if(j+x[k]<0||i+y[k]<0||j+x[k]>=W||i+y[k]>=H){
            continue;
          }
          if(A.at(i+y[k]).at(j+x[k])=='#'){
            flag2 = 1;
          }
        }
        if(flag2 == 0){
          flag = 1;
        }
      }
    }
  }

  if(flag == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}