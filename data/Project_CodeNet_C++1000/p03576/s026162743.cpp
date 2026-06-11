#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;long long x[50],y[50];
  cin >>n>>k;
  for (int i=0;i<n;i++){
    cin >>x[i]>>y[i];
  }
  long long ans = 9223372036854775807;
  for (int i1=0;i1<n;i1++){
    for (int i2=0;i2<n;i2++){
      for (int i3=0;i3<n;i3++){
        for (int i4=0;i4<n;i4++){
          int l = 0;
          for (int j=0;j<n;j++){
            if (x[i1]<=x[j] && x[j]<=x[i2] && y[i3]<=y[j] && y[j]<=y[i4]){
              l++;
            }
          if (l==k){
            ans = min (ans, abs((x[i1] - x[i2]) * (y[i3] -y[i4])));
  }
  }
  }
  }
  }}
  cout <<ans<<endl;}
