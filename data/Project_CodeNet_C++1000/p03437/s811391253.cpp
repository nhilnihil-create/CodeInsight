#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> P;
typedef pair<ll,pair<ll,ll>> p;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
static const int MAX_SIZE = 1 << 17; //segment tree のサイズ。この実装では2べきにする必要がある。 2^17 ≒ 1.3 * 10^5

int dp[110000][2];


int main(){
  ll x,y;
  cin>>x>>y;

  if(x%y==0) cout<<-1<<endl;
  else{
      ll i=2;
      while(true){
          if(x*i%y!=0){
              cout<<x*i<<endl;
              return 0;
          }
          i++;
      }
  }
}

