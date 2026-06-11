#include <algorithm>
#include <cassert>
// #include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
// #include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

char buf[10000];
vector<int> poss[2];
int goal[2];

bool dp[10000];

bool can(int idx) {
  memset(dp, 0, sizeof(dp));
  dp[0] = true;
  int totalSum = 0;
  for(int out: poss[idx]) {
    totalSum += out;
    for(int a = 8000; a >= out; a--) {
      dp[a] |= dp[a-out];
    }
  }
  goal[idx] = abs(goal[idx]);
  if(goal[idx] > totalSum) return false;
  if(totalSum%2 != goal[idx]%2) return false;
  return dp[(totalSum - goal[idx]) / 2];
}

bool can() {
  return can(0) && can(1);
}

int main() {
  scanf("%s", buf);
  int len = strlen(buf);
  scanf("%d%d", &goal[0], &goal[1]);
  int idx = 0;
  int i = 0;
  while(i < len && buf[i] == 'F') {
    goal[0]--;
    i++;
  }
  i++;
  idx++;
  while(i < len) {
    if(buf[i] == 'T') {
      idx++;
      idx%=2;
      i++;
      continue;
    }
    int j = i+1;
    while(j < len && buf[j] == 'F') j++;
    poss[idx++].push_back(j-i);
    idx%=2;
    i=j+1;
  }
  printf(can() ? "Yes\n" : "No\n");
}
