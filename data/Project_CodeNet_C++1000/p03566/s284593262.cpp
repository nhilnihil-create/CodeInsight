#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define FOR(i, j, limit) for(int i=j; i< limit; ++i)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ECHO(x) cout<<x<<endl;
#define LL long long
int INF = 2147483647;
LL LINF = 9223372036854775807;
LL MOD = 1000000007;
typedef pair<int, int>P;
typedef pair<LL, LL>PL;
typedef vector<int> vi;
typedef vector<LL> vl;

vector<int> t;
vector<int> v;
vector<int> h;
int func(int tt, int i){
  int ht;
  if(tt<=t[i-1]) ht = v[i] + (t[i-1]-tt);
  else if(tt>t[i-1] && tt<=t[i]) ht = v[i];
  else ht = v[i] + (tt-t[i]);
  return ht;
}

int main(){
  int n;
  cin>>n;
  t.push_back(0);
  v.push_back(0);
  int temp;
  REP(i, n){
    cin>>temp;
    temp=2*temp + t[i];
    t.push_back(temp);
  }
  int tmax=t[n];
  t.push_back(40002);
  REP(i, n){
    cin>>temp;
    temp *= 2;
    v.push_back(temp);
  }
  v.push_back(0);

  for(int a=0; a<=tmax; ++a){
    int ht=INF;
    //cout<<a<<" ";
    ht=min({ht, a, tmax-a});
    for(int i=1; i<=n; ++i){
      ht = min(ht, func(a, i));
    }
    //cout<<ht<<endl;
    h.push_back(ht);
  }
  double ans=0;
  REP(i, h.size()-1){
    ans += double(h[i+1]+h[i])/2;
    //cout<<ans<<endl;
  }
  ans /=4;
  printf("%.4f\n", ans);



  return 0;
}
