#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
using ll = long long int;
const lint INF = 1001001001001001LL;
const lint MOD = 1000000007LL;
int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

void yes(){ cout << "yes" << endl; }
void Yes(){ cout << "Yes" << endl; }
void YES(){ cout << "YES" << endl; }
void no(){ cout << "no" << endl; }
void No(){ cout << "No" << endl; }
void NO(){ cout << "NO" << endl; }
void possible(){ cout << "possible" << endl; }
void Possible(){ cout << "Possible" << endl; }
void POSSIBLE(){ cout << "POSSIBLE" << endl; }
void impossible(){ cout << "impossible" << endl; }
void Impossible(){ cout << "Impossible" << endl; }
void IMPOSSIBLE(){ cout << "IMPOSSIBLE" << endl; }

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for(int i = s; i < t; i++)
#define all(a) a.begin(),a.end()

int main(){
  
  lint h, w, n; cin >> h >> w >> n;
  vector<lint> x(n);
  vector<lint> y(n);
  rep(i, n) cin >> x[i] >> y[i];
  set<pair<lint, lint>> allPointSets;
  vector<set<lint>> xPointSets(h + 1);
  rep(i, n){ 
    allPointSets.insert({x[i], y[i]});
    xPointSets[x[i]].insert(y[i]);
  }

  lint maxHeight = 1;
  srep(i, 1, h){
    //cerr << "(" << i << ", " << maxHeight << ")" << endl;
    
    // i + 1 に maxHeight 以下にあれば終わりや
    for(auto val : xPointSets[i + 1]){
      if(val <= maxHeight){
        cout << i << endl;
        return 0;
      } 
    }

    // (i + 1, maxHeight + 1) に存在しなければ
    if(allPointSets.find({i + 1, maxHeight + 1}) == allPointSets.end()){
      maxHeight++;
    }
  }

  cout << h << endl;
  
  return 0;
}
