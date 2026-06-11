#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string N;
  cin>>N;
  queue<string> que;
  que.push("3");
  que.push("5");
  que.push("7");
  string state;
  bool ok;
  int ans = 0;
  while(true){
    state = que.front();que.pop();
    map<char, int> amap;
    ok = true;
    for(int i=0;i<state.size();++i){
      amap[state[i]]++;
    }
    if(!(amap['3']>0 && amap['5']>0 && amap['7']>0)) ok = false;
    if(state.size()>N.size()) break;
    else if(state.size()==N.size()){
      for(int i=0;i<N.size();++i){
        if(state[i]>N[i]) ok = false;
        if(state[i]<N[i]) break;
      }
    }
    if(ok) ans++;
    que.push(state+'3');
    que.push(state+'5');
    que.push(state+'7');
  }
  cout<<ans<<endl;
}
