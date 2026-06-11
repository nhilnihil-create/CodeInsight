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
  int n;
  cin>>n;
  ll sum=0;
  ll v[5];
  memset(v,0,sizeof(v));
  REP(i,n){
    string s;
    cin>>s;
    if(s[0]=='M')v[0]++;
    if(s[0]=='A')v[1]++;
    if(s[0]=='R')v[2]++;
    if(s[0]=='C')v[3]++;
    if(s[0]=='H')v[4]++;
  }
  for(int i=0;i<3;i++){
    for(int j=i+1;j<4;j++){
      for(int k=j+1;k<5;k++){
        sum+=v[i]*v[j]*v[k];
      }
    }
  }
  cout<<sum<<endl;
}