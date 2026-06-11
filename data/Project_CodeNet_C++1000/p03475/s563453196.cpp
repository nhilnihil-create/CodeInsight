#include<bits/stdc++.h>
using namespace std;
long long ks(long long x,long long y){
  if(x%y==0) return x;
  else return y*(x/y+1);
}
int main(){
  long long n,i,j,c,s,f,now;cin >> n;
  long long k[n-1][3];
  for(i=0;i<n-1;i++) cin >> k[i][0] >> k[i][1] >> k[i][2];
  for(i=0;i<n;i++){
    now = 0;
    for(j=i;j<n-1;j++){
      if(now<=k[j][1]) now = k[j][1];
      else now = ks(now,k[j][2]);
      now += k[j][0];
    }
    cout << now << "\n";
  }
}
  
    