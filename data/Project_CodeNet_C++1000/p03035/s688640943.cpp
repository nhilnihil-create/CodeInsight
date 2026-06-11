#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
typedef long long ll;
typedef pair<int,int> P;
#define F first
#define S second
const double PI=acos(-1);
//fixed<<setprecision(11)<<

int main(){
  int a,b;
  cin>>a>>b;
  if(13<=a) cout<<b<<endl;
  else if(6<=a&&a<=12) cout<<b/2<<endl;
  else if(a<=5) cout<<0<<endl;
return 0;
}