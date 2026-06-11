#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main() {
  string s;
  cin>>s;
  bool ans=false;
  for(int i=0;i<len(s);i++){
    for(int j=i;j<len(s);j++){
      string t=s.substr(0,i)+s.substr(j);
      if(t=="keyence"){
        ans=true;
      }
    }
  }
  cout<<(ans?"YES":"NO")<<endl;
}