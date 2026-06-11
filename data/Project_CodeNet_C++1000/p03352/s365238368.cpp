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
  int x;
  cin>>x;
  int ans=INF;
  if(x==1||x==2||x==3){
    cout<<1<<endl;
    return 0;
  }
  for(int i=2;i<=32;i++){
  int cnt=0;
    for(int j=2;pow(i,j)<=x;j++){
      cnt=pow(i,j);
    }
    cnt=x-cnt;
    ans=min(cnt,ans);
  }
  cout<<x-ans<<endl;
}