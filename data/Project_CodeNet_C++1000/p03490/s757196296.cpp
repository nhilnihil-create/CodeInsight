#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;


bool dp[2][9010][36010];

int main() {
  string s;cin >> s;
  int x,y;cin >> x >> y;
  vint d[2];
  int N = s.length();
  bool isy=false;
  bool is0=true;
  repeat(i,N){
    if(s[i] == 'T'){
      isy = !isy;
      is0 = false;
      d[isy].push_back(0);
    }else{
      if(is0){
        x--;
      }else{
        d[isy].back()++;
      }
    }
  }
  //debugArray(d[0],xsize);
  //debugArray(d[1],ysize);
  dp[0][0][18000]=true;
  dp[1][0][18000]=true;
  repeat(k,2){
    repeat(i,d[k].size()){
      repeat(z,36000){
        int nz = z+d[k][i];
        if(0<=nz&&nz<=36000){
          dp[k][i+1][nz] |= dp[k][i][z];
        }
        nz = z-d[k][i];
        if(0<=nz&&nz<=36000){
          dp[k][i+1][nz] |= dp[k][i][z];
        }
      }
    }
  }
  cout << (dp[0][d[0].size()][x+18000]&&dp[1][d[1].size()][y+18000]? "Yes":"No")<<endl;
  return 0;
}
