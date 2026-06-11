#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;
const int INF = 1 << 28;

string to_string(string s) {
  return s;
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() {
  cerr << endl;
}

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

void get() {}

template <class Head, class... Tail>
void get(Head& head, Tail&... tail) {
  cin >> head;
  get(tail...);
}

template <class T>
void getv(vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i)
    cin >> vec[i];
}

struct Union_Find {
  vector<int> data;
  vector<int> dist;
  Union_Find(int size) { data = vector<int>(size, -1);dist=vector<int>(size,0); }
  bool union_set(int x, int y) {
    x = root(x);

    y = root(y);
    if (x != y) {
      if (data[y] < data[x])
        swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : root(data[x]); }
  int size(int x) { return -data[root(x)]; }
  int get_dist(int x){
    int dis=0;
    while(data[x]>=0){
      dis+=dist[x];
      x=data[x];
    }
    return dis;
  }
};

int main() {
  int N,M;
  get(N,M);
  Union_Find uf(N);
  FOR(i,M){
    int L,R,D;
    get(L,R,D);
    L--;R--;
    if(uf.find(L,R)){
      if(uf.get_dist(L)+D!=uf.get_dist(R)){
        print("No");
        return 0;
      }
    }else{
      if(uf.data[uf.root(L)]>uf.data[uf.root(R)]){
        swap(L,R);
        D=-D;
      }
      int rt=uf.root(R),dis=uf.get_dist(R);
      uf.dist[rt]=D-dis+uf.get_dist(L);
      uf.union_set(L,R);
    }
  }
  print("Yes");
  return 0;
}
