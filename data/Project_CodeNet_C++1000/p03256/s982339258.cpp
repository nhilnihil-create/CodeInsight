#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int N, M;
string s;
vector<vector<int> > G;
vector<set<int> > haveA, haveB; // 繋がってるAの頂点、Bの頂点情報
vector<bool> del;
void rec(int v) {
  if(del[v]) return;
  if(haveA[v].empty() || haveB[v].empty()) {
    del[v] = true;
    for(int to : G[v]) {
      haveA[to].erase(v);
      haveB[to].erase(v);
      rec(to);
    }
  }
  
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> s;
  G.resize(N+1);
  haveA.resize(N+1);
  haveB.resize(N+1);
  del.resize(N+1, false);
  FOR(i,0,M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    if(s[b-1]=='A') {
      haveA[a].insert(b);
    } else {
      haveB[a].insert(b);
    }
    G[b].push_back(a);
    if(s[a-1]=='A') {
      haveA[b].insert(a);
    } else {
      haveB[b].insert(a);
    }
  }
  FOR(i,1,N+1) {
    if(!del[i]) rec(i);
  }
  FOR(i,1,N+1) {
    if(!del[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}