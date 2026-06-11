#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int digit_sum(int N){
  string s=to_string(N);
  int sum=0;
  for(int i=0;i<(int)s.size();i++){
    sum+=(s[i]-'0');
  }
  return sum;
}

int main() {
  int n,a,b;
  cin>>n>>a>>b;
  int ans=0;
  for(int i=1;i<=n;i++){
    int sum=digit_sum(i);
    if(sum>=a&&sum<=b)
      ans+=i;
  }
  cout<<ans<<"\n";

  return 0;
}
