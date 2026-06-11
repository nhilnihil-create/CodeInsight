# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

struct Edge {
  int from, to, weight;
  Edge(){}
  Edge(int f, int t, int w){
    from = f;
    to = t;
    weight = w;
  }
};

int getValue(int x){
  int res = 0, cur = 1;
  while(cur * 2 <= x){
    cur *= 2;
    res++;
  }
  return res;
}

vector<Edge> getAns(int L, int N){
  vector<Edge> res;
  for(int i=0; i<N; i++){
    res.push_back(Edge(i+1, i+2, 0));
    res.push_back(Edge(i+1, i+2, 1<<i));
  }
  for(int t=N; t>=0; t--){
    if(L - (1<<t) >= (1<<N)){
      res.push_back(Edge(t+1, N+1, L-(1<<t)));
      L -= 1<<t;
    }
  }
  return res;
}

int main(){

  ios :: sync_with_stdio(false);
  int L;
  cin >> L;

  int N = getValue(L);
  vector<Edge> ans = getAns(L, N);

  cout << N+1 << " " << ans.size() << endl;
  for(auto e : ans) cout << e.from << " " << e.to << " " << e.weight << endl;
  return 0;
}