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
  ll n,m;
  cin>>n>>m;
  if(n==1&&m==1){
    cout<<1<<endl;
  }else if(n==1||m==1){
    if(n==1){
      cout<<m-2<<endl;
    }else{
      cout<<n-2<<endl;
    }
  }else if(n==2||m==2){
    cout<<0<<endl;
  }else{
    cout<<(n-2)*(m-2)<<endl;
  }
}
