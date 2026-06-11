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
 
int main(){
  int n;
  string s;
  cin>>n>>s;
  int ans=0;
  for(int i=1;i<n;i++){
    int cnt=0;
    map<char,int> mpx;
    map<char,int> mpy;
    for(int j=0;j<i;j++){
      mpx[s[j]]++;
    }
    for(int j=i;j<n;j++){
      mpy[s[j]]++;
    }
    for(auto x:mpx){
      for(auto y:mpy){
        if(x.first==y.first&&x.second>0&&y.second>0){
          cnt++;
        }
      }
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}
