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
vector<vector<int> > G; //
vector<int> visited;
void rec(int v) {
  visited[v] = -1;
  for(auto& to : G[v]) {
    if(visited[to] == -1) {
      cout << "Yes" << endl;
      exit(0);
    } else if(!visited[to]){
      rec(to);
    }
  }
  visited[v] = 1;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> s;
  G.resize(N * 2);
  visited.resize(N * 2, false);
  FOR(i,0,M) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    if(s[a]==s[b]) {
      G[a].push_back(b+N);
      G[b].push_back(a+N);
    } else {
      G[a+N].push_back(b);
      G[b+N].push_back(a);
    }
  }
  FOR(i,0,N) {
    if(!visited[i]) {
      rec(i);
    }
  }
  cout << "No" << endl;
  return 0;
}