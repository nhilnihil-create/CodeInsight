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
  int sum=0;
  vector<int> v;
  vector<int> x;
  v.push_back(0);
  REP(i,n){
    int tmp;
    cin>>tmp;
    v.push_back(tmp);
    x.push_back(abs(v[i]-tmp));
    sum+=x[i];
  }
  x.push_back(abs(v[n]-v[0]));
  sum+=x[n];
  REP(i,n){
    int ans=sum;
    if(i!=n-1){
      ans=ans-x[i]-x[i+1];
      ans+=abs(v[i]-v[i+2]);
      cout<<ans<<endl;
    }else{
      ans=ans-x[n]-x[n-1];
      ans+=abs(v[0]-v[n-1]);
      cout<<ans<<endl;
    }
  }

}