#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll N;
  cin >> N;
  vector<ll> vec;
  vec.push_back(3);
  vec.push_back(5);
  vec.push_back(7);
  vector<ll> vec2(vec);
  REP(i,8){
    vector<ll> vec3;
    for(auto x:vec2){
      vec3.push_back(x*10+3);
      vec3.push_back(x*10+5);
      vec3.push_back(x*10+7);
      vec.push_back(x*10+3);
      vec.push_back(x*10+5);
      vec.push_back(x*10+7);
    }
    vec2=vec3;
  }
  sort(ALL(vec));
  int cnt=0;
  REP(i,vec.size()){
    set<int> st;
    ll y = vec.at(i);
    while(y>0){
      st.insert(y%10);
      y/=10;
    }
    if(N>=vec.at(i)&&st.size()==3){
      cnt++;
    }else if(N<vec.at(i)){
      break;
    }
  }

  cout << cnt << endl;
}