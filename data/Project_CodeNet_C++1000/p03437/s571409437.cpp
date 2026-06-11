#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int x,y;
  cin>>x>>y;

  if(x%y==0){
    cout<<-1<<endl;
    return 0;
  }
  ll v=1;
  while(v<=1e18){
    v*=x;
    if(v%y) break;
  }
  cout<<v<<endl;
	return 0;
}