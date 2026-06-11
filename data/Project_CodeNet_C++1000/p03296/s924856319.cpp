#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int n;
  cin>>n;
  vector<int> a(n);
  int cnt=1,ans=0;
  REP(i,n){
    cin>>a[i];
    if(i!=0){
      if(a[i-1]==a[i]){
        cnt++;
        if(cnt%2==0) ans++;
      }else cnt=1;
    }
  }

  cout<<ans<<endl;

  return 0;
}