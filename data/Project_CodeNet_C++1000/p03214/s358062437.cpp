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
  int sum=0;
  REP(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  double mean=sum/double(n);
  vector<int> b=a;
  sort(ALL(b));
  int v,w;
  REP(i,n){
    if(mean<=b[i]){
      if(mean-b[i-1]<b[i]-mean) v=b[i-1];
      else if(mean-b[i-1]>b[i]-mean) v=b[i];
      else {v=b[i-1];w=b[i];}
      break;
    }
  }
  int ans;
  REP(i,n)
    if(a[i]==v || a[i]==w){
      ans=i;
      break;
    }
  cout<<ans<<endl;

  
	return 0;
}