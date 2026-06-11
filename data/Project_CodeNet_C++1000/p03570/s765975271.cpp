#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;
//-------------------------------------------------------------------
#include <sstream>
#include <fstream>
ifstream ifs;
void init(string s){ifs.open(s);}
vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while(getline(ss, buffer, sep)) v.push_back(buffer);
    return v;
}
ll read(){
  string str;
  getline(ifs, str);
  return stoll(str);
}
string read_str(){
  string str;
  getline(ifs, str);
  return str;
}
vector<ll> read_vec(){
  string str;
  getline(ifs, str);
  std::vector<ll> num;
  vector<string> data = split(str, ' ');
  for(int i=0;i<data.size();i++) num.push_back(stoll(data[i]));
  return num;
}
vvl read_mat(ll h){
  string str;
  vvl num = vv(h, 0, 0, ll);
  for(int i=0;i<h;i++){
    getline(ifs, str);
    vector<string> data = split(str, ' ');
    for(int j=0;j<data.size();j++) num[i].push_back(stoll(data[j]));
  }
  return num;
}
//-------------------------------------------------------------------

struct Dijkstra{
  ll INF=1000000000000000009;
  ll MAX_V=1000000;
  ll st = -1;
  struct edge{ll to, cost;};
  typedef pair<ll, ll> p;
  vector<vector<edge>> G;
  vector<ll> pre, d;
  priority_queue<p, vector<p>, greater<p> > que; //class, inner, compair
  Dijkstra(ll s){
    G.resize(s+2);
    pre.resize(s+2, -1);
    d.resize(s+2, INF);
  }
  inline void insert(ll a, ll b, ll c){
    G[a].push_back(edge{b, c});
  }
  void init(){
    for(int i=0;i<d.size();i++) pre[i] = -1, d[i] = INF;
  }
  void dijkstra(int start){
    init();
    st = start;
    d[start]=0;
    que.push(p(0, start));
    while(!que.empty()){
      p p_now=que.top(); que.pop();
      ll v = p_now.second;
      if(d[v]<p_now.first) continue;
      for(int i=0;i<G[v].size();i++){
        edge e = G[v][i];
        if(d[e.to]>d[v]+e.cost){
          d[e.to]=d[v]+e.cost;
          pre[e.to] = v;
          que.push(p(d[e.to], e.to));
        }
      }
    }
  }
  vll get_path(int now){
    vll ret;
    while(now!=-1){
      ret.push_back(now);
      now = pre[now];
    }
    return ret;
  }
};
int main(int argc, char const *argv[]) {
  init("2.in");
  string s;
  //s=read_str();
  std::cin >> s;
  ll n = s.size(), num=0;
  set<vll> mp;
  vll m(n);
  mp.insert(vll{0, 0});
  for(int i=0;i<n;i++){
    num^=(1<<(s[i]-'a'));
    m[i] = num;
    mp.insert(vll{num, i+1});
  }
  Dijkstra dj(200001);
  for(int i=1;i<=n;i++){
    dj.insert(i-1, i, 1);
    for(int j=0;j<27;j++){
      ll t = m[i-1];
      t = (j==26?t:t^(1<<j));
      auto itr = mp.lower_bound(vll{t, i});
      if(itr==mp.begin()) continue;
      itr--;
      if((*itr)[0]!=t) continue;
      dj.insert((*itr)[1], i, (j==26?0:1));
    }
  }
  dj.dijkstra(0);
  std::cout << (dj.d[n]==0?1:dj.d[n]) << '\n';
  return 0;
}
