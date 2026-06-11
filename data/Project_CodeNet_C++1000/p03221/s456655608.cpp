#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
 
#include <complex>
 
#include <functional>
#include <cassert>
 
typedef long long ll;
using namespace std;
 
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
 
 
#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010
 
 
int main(){
  int n, m;
  vector<pair<int,int> > vec[SIZE];
  char ans[SIZE][13];
  
  scanf("%d%d", &n, &m);
 
  for(int i=0;i<m;i++){
    int p, y;
    scanf("%d%d", &p, &y);
    vec[p].push_back({y, i});
  }
 
  for(int i=0;i<=n;i++){
    sort(vec[i].begin(), vec[i].end());
 
    for(int j=0;j<vec[i].size();j++){
      sprintf(ans[vec[i][j].second], "%06d%06d", i, j+1);
    }
  }
 
  for(int i=0;i<m;i++){
    printf("%s\n", ans[i]);
  }
  
  return 0;
}