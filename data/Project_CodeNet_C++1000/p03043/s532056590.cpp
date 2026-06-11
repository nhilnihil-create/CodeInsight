#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n,k;
  cin >> n>>k;
  vector<int> ni(21);
  ni.at(0)=1;
  int x=1;
  for(int i=1;i<21;i++){
    x=x*2;
    ni.at(i)=x;
  }
  double ans=0;
  for(int i=1;i<=n;i++){
    double p=(double)k/i;
    double ke=1;
    if(i>=k){
      ans++;
      continue;
    }
    for(int j=0;j<21;j++){
      if(ni.at(j)>=p){
        ans+=ke;
        break;
      }
      ke/=2;
    }
  }
  ans/=n;
  printf("%.10lf\n",ans);
}
 