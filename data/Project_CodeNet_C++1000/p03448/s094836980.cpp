#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  int a,b,c,x;
  cin>>a>>b>>c>>x;
  int ans=0;
  for(int i=0;i<=a;i++){
    for(int j=0;j<=b;j++){
      int sum=x - 500 * i - 100 * j;
      //cout<<x<<endl;
      if(sum >= 0 && sum % 50 == 0 && sum / 50 <= c){
        ans++;
      }
    }
  }
  cout<<ans<<"\n";

  return 0;
}
