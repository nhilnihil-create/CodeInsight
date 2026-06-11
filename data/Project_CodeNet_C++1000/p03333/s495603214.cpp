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
  int n, l, r;
  vector<int> vecL, vecR;
  
  scanf("%d", &n);

  for(int i=0;i<n;i++){
    scanf("%d%d", &l, &r);
    vecL.push_back(l);
    vecR.push_back(r);
  }

  sort(vecL.begin(), vecL.end(), greater<int>());
  sort(vecR.begin(), vecR.end());

  ll ans1 = 0, ans2 = 0;
  ll pos1 = 0, pos2 = 0;
  
  for(int i=0;i<n;i++){
    if(pos1 >= vecL[i]) break;
    ans1 += vecL[i] - pos1;
    pos1 = vecL[i];

    if(vecR[i] >= pos1) break;
    ans1 += pos1 - vecR[i];
    pos1 = vecR[i];
  }

  for(int i=0;i<n;i++){
    if(vecR[i] >= pos2) break;
    ans2 += pos2 - vecR[i];
    pos2 = vecR[i];
    
    if(pos2 >= vecL[i]) break;
    ans2 += vecL[i] - pos2;
    pos2 = vecL[i];
  }

  cout << max(ans1 + abs(pos1), ans2 + abs(pos2)) << endl;
  
  
  return 0;
}
