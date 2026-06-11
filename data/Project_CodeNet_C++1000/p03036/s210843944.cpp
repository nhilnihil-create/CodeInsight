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
  int r,d,x;
  cin>>r>>d>>x;
  for(int i=1;i<=10;i++){
  x=r*x-d;
  cout<<x<<endl;
  }
return 0;
}