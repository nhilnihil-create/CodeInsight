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
  int n;
  cin>>n;
  vector<int> L(n);
  rep(i,n) cin>>L[i];

  sort(L.begin(),L.end());
  int sum=0;
  rep(i,n-1) sum+=L[i];

  if(L[n-1]<sum) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
return 0;
}