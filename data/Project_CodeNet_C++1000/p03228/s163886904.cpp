#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int a,b,k;
  cin>>a>>b>>k;

  bool f=1;
  REP(i,k){
    if(f){
      if(a%2) a--;
      b+=a/2;
      a/=2;
      f=0;
    }else{
      if(b%2) b--;
      a+=b/2;
      b/=2;
      f=1;
    }
  }

  cout<<a<<" "<<b<<endl;

  return 0;
}