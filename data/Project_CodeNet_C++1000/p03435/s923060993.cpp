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
  vector<int> c(9);
  rep(i,9)cin>>c[i];
  if(c[0]+c[4]==c[1]+c[3]&&c[1]+c[5]==c[2]+c[4]&&c[3]+c[7]==c[4]+c[6]&&c[4]+c[8]==c[5]+c[7]){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}