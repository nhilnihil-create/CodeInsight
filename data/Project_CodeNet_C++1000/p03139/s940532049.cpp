#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int n,a,b;
  cin>>n>>a>>b;

  cout<<((a<b)? a:b)<<" "<<((a+b>n)? a+b-n:0)<<endl;

  return 0;
}