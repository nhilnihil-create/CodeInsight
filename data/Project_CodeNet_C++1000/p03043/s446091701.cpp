#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  double ans=0;
  for(int i=0;i<n;i++){
    double j=1;
    int p=i+1;
    while(p<k){
      p*=2;
      j/=2;
    }
    ans+=j;
  }
  ans/=n;
  printf("%.15f\n",ans);
}