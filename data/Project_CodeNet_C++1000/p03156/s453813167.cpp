#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
  int n,a,b;
  cin >> n >> a >> b;
  VI p(n);
  rep(i,n)cin >> p.at(i);
  int x=0;
  int y=0;
  int z=0;
  rep(i,n){
      if(p.at(i)<=a)x++;
      else if(p.at(i)<=b)y++;
      else z++;
  }
  int ans=min(x,y);
  ans=min(ans,z);
  cout << ans << endl;
}