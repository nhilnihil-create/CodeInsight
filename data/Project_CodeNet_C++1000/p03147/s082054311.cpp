#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;

#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl

/*
0,0,0,0というやつを
水やりして
1,2,2,1にする
*/

bool isnull(vector<int> h)
{
  int n=h.size();
  for (int i=0;i<n;i++)
  { 
    if (h[i]!=0) return (false);
  }
  return (true);
}
 
int main()
{
  int N;cin>>N;
  vector<int> h(N);
  for (int i=0;i<N;i++)
    cin>>h[i];
  
  int i=0;
  int count=0;
  while (!isnull(h))
  {
    i=0;
    while (h[i]==0)
    {
      i++; 
    }
    while (h[i]>=1)
    {
      h[i]-=1;
      i++;
    }
    count++;
  }
  cout<<count<<endl;
}