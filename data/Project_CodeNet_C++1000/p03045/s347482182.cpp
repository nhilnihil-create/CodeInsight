#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // long long64_t, long long*_t
#include <cstdio> // prlong longf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
#include <sstream> //istringstream
#include <stdlib.h>
#include <list>
#include <iterator>//std::advance()
using namespace std;
vector<int> par;
vector<int> RANK;

//初期化,par[i]==iなら根だしRANK=0なら何も繋がってない
void init(int n){
  for(int i=0; i<n; i++){
    par.push_back(i);
    RANK.push_back(0);
  }
  return;
}

//根を返す関数
int root(int x){
  if(par[x]==x){
    return x;
  }
  return par[x]=root(par[x]);//経路圧縮
}

//xとyが同じ集合に属するか否か．
bool same(int x, int y){
  return root(x)==root(y);
}

//xとyの属する集合を併合
void merge(int x, int y){
  x=root(x);
  y=root(y);
  if(x==y) return;
  if(RANK[x]<RANK[y]){
    par[x]=y;//『「元のx」の根』の根を「元のy」の根にする（高い方につなげるので）
  }
  else{
    par[y]=x;
    if(RANK[x]==RANK[y]) RANK[x]++;//根に同じ長さのが増えるから高さが1つ増える
  }
  return;
}

int main(){
  int n,m;
  cin >> n >> m;
  init(n);
  for(int i=0; i<m; i++){
    int x,y,z;
    cin >> x >> y >> z;
    merge(x-1,y-1);
  }
  int sum=1;
  vector<int> isroot(n);
  for(int i=0; i<n; i++) isroot[i]=root(i);
  sort(isroot.begin(),isroot.end());
  for(int i=0; i<n-1; i++){
    if(isroot[i]!=isroot[i+1]) sum++;
  }
  cout << sum << endl;
}
