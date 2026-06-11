#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  vector<int> c(4);
  bool f=0;
  REP(i,6){
    int x;
    cin>>x;
    c[x-1]++;
    if(c[x-1]==3) f=1;
  }

  cout<<(f? "NO":"YES")<<endl;

  return 0;
}