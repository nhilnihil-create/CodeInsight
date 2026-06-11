#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,a,n,m,x;
  vector<int> y(110,0);
  cin >> n >> m >> x;
  for(i=0;i<m;i++){
    cin >> a;
    y[a]=1;
  }
  int ans=(1<<29),sum=0;
  for(i=x;i<=n;i++){
    if(y[i]==1){
      sum++;
    }
  }
  if(ans>sum){
    ans=sum;
  }
  sum=0;
  for(i=x;i>=0;i--){
    sum+=y[i];
  }
  if(ans>sum){
    ans=sum;
  }
  cout << ans << endl;
}