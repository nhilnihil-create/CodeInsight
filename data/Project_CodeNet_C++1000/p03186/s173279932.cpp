#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  if(a+b>=c-1){
    cout<<b+c<<endl;
    return 0;
  }else{
    ll mi=min(c,a+b+1);
    cout<<b+mi<<endl;
  }
}