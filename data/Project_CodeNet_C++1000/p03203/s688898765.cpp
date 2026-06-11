#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int main(){
  int H,W,N;cin>>H>>W>>N;
  vector<vll> array(W);
  repeat(i,N){
    int x,y;cin>>x>>y;
    x--;y--;
    array[y].push_back(x);
  }
  repeat(i,W){
    array[i].push_back(H);
    sort(array[i].begin(),array[i].end());
  }
  ll ans = H;
  ll y=0;
  repeat(i,H){
    //debug(i);
    //debug(y);
    int idx = lower_bound(array[y].begin(),array[y].end(),i+1)-array[y].begin();
    //debug(array[y][idx]);
    ans = min(ans,array[y][idx]);
    if(array[y][idx]==i+1){
      break;
    }
    //debug(ans);
    if(y+1>=W)break;
    idx = lower_bound(array[y+1].begin(),array[y+1].end(),i+1)-array[y+1].begin();
    if(array[y+1][idx]!=i+1){
      y++;
    }
  }
  cout << ans << endl;
  return 0;
}
