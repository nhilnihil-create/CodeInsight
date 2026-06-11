#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;


int main() {
 int a,b,c;
  cin>>a>>b>>c;
  int k;
  cin>>k;
  int ans=0;
  int x=max(max(a,b),c);
 ans=a+b+c-x;
  ans+=x*pow(2,k);
  cout<<ans<<endl;
}