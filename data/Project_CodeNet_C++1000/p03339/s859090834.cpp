#include <bits/stdc++.h>

using namespace std;

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define LOOP(i, N) for (int i = 1; i <= (int)N; i++)
#define RREP(i, N) for (int i =(int)N-1; i >= 0; i--)
#define RLOOP(i, N) for (int i =(int)N; i > 0; i--)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define INF (1 << 30)
#define LLINF (1LL << 62)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
string s;
int n;
int main(){
  cin>>n>>s;
  int min=INF;
  vector<int> w;
  vector<int> e;
  w.push_back(0);
  e.push_back(0);
  REP(i,n){
    if(s[i]=='W'){
      w.push_back(w[i]+1);
      e.push_back(e[i]);
    }else{
      w.push_back(w[i]);
      e.push_back(e[i]+1);
    }
  }
  REP(i,n){
    if(w[i]-w[0]+e[n]-e[i+1]<min){
      min=w[i]-w[0]+e[n]-e[i+1];
    }
  }
  cout<<min<<endl;
}