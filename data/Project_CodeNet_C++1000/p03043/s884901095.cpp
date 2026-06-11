#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n,k;
  cin >> n >> k;
  double ans=0;
  for(int i=1;i<=n;i++){
    int p=i;
    double ct=1;
    if(i>=k){
      ans+=1;
      continue;
    }
    while(p<k){
      p=p*2;
      ct=ct/2;
    }
    ans+=ct;
  }
  printf("%.10lf",ans/n);
}