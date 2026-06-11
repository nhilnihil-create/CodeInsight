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

int main(){
  int n,k;
  cin>>n>>k;
  int v[n+1];
  memset(v,0,sizeof(v));
  int sum=0;
  int x=0;
  REP(i,n){
    int tmp;
    cin>>tmp;
    if(v[tmp]==0)x++;
    v[tmp]++;
  }
  sort(v,v+n+1);
  int i=1;
  while(x>k&&i<=n+1){
    if(v[i]!=0){
      sum+=v[i];
      x--;
    }
    i++;
  }
  cout<<sum<<endl;
}