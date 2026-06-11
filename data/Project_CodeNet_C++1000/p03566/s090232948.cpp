#include <bits/stdc++.h>

using namespace std;

int main(){
 long n;
   cin >> n;
   
  long t[n+1],v[n+1];
  t[0]=0;
  v[0]=0;
  for(long i=1;i<=n;i++) {
    cin >> t[i];
    t[i]+=t[i-1];
  }
  for(long i=1;i<=n;i++) cin >> v[i];

  long res=0;
  long right=0;
  for(long i=1;i<2*t[n]+1;i++){
   long left=right;
   right=min(i,2*t[n]-i);
    for(long j=1;j<=n;j++){
     if(i<=2*t[j-1]) right=min(right,2*v[j]+2*t[j-1]-i);
     else if(2*t[j]<=i) right=min(right,2*v[j]+i-2*t[j]);
     else right=min(right,2*v[j]);
    }
    res+=(left+right);
  }
  
   cout << setprecision(12) << double(res)/8.0 << endl;
}