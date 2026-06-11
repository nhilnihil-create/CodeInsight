#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=1000010;
const ll mod=1e9+7;

int main(){
  ll n,m;
  cin >> n >> m;
  vector<int> v[n];
  rep(i,m){
    int a,b; cin >> a >> b; a--; b--;
    v[a].emplace_back(b);
    v[b].emplace_back(a);
  }

  vector<int> d(n,-1);
  d[0]=0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int p = q.front(); q.pop();
    for(auto it:v[p]){
      if(d[it] != -1){
        if(d[it]%2 == d[p]%2){
          cout << n*(n-1)/2-m << endl; return 0;
        }
      } else {
        d[it] = d[p]+1;
        q.emplace(it);
      }
    }
  }
  ll b=0,w=0;
  rep(i,n){
    if(d[i]%2){b++;}else{w++;}
  }
  cout << b*w-m << endl;
  return 0;
}