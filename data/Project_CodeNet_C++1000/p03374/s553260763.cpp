#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, c, x[100005], v[100005];
int A[100005], maxA[100005];
int B[100005], maxB[100005];

signed main(){
  
  cin>>n>>c;
  
  for(int i=0;i<n;i++) cin>>x[i]>>v[i];
  
  A[0] = v[0] - x[0];
  maxA[0] = max( maxA[0], A[0] );
    
  for(int i=1;i<n;i++){
    A[i] = v[i] - ( x[i] - x[i-1] ) + A[i-1];
    maxA[i] = max( maxA[i], maxA[i-1] );
    maxA[i] = max( maxA[i], A[i] );
  }
  
  B[n-1] = v[n-1] - ( c - x[n-1] );
  maxB[n-1] = max( maxB[n-1], B[n-1] );
  
  for(int i=n-2;i>=0;i--){
    B[i] = v[i] - ( x[i+1] - x[i] ) + B[i+1];
    maxB[i] = max( maxB[i], maxB[i+1] );
    maxB[i] = max( maxB[i], B[i] );
  }
  
  int ans = 0;
  
  for(int i=0;i<n;i++){
    
    ans = max( ans, A[i] );
    
    ans = max( ans, B[i] );
    
    if( i < n - 1 ) ans = max( ans, A[i] - x[i] + maxB[i+1] );
    
    if( i ) ans = max( ans, B[i] - ( c - x[i] ) + maxA[i-1] );
    
  }
  
  cout<<ans<<endl;
  
  return 0;
}
