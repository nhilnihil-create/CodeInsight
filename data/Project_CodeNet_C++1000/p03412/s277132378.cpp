#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, a[200005], b[200005], A[31][200005], B[31][200005];

void init(){
  
  int k = 2;
  
  for(int idx=1;idx<=30;idx++){
    
    for(int i=0;i<N;i++){
      A[idx][i] = a[i] % k;
      B[idx][i] = b[i] % k;
    }
    
    sort( B[idx], B[idx] + N );
    
    k *= 2;
            
  }
  
}

int get(int l, int r, int idx){ // [ l, r )
  auto L = lower_bound( B[idx], B[idx] + N, l );
  auto R = lower_bound( B[idx], B[idx] + N, r );

  return max( 0LL, (int)( R - L + 1 ) );
}

void solve(){
  
  int ans = 0;
  
  for(int i=1;i<30;i++){
    
    int cnt = 0;
    
    for(int j=0;j<N;j++){
      
      int num = A[i][j], T = 1<<(i-1);
      
      cnt += get( T - num, 2 * T - num, i );
      
      cnt += get( 3 * T - num, 4 * T - num, i );
      
    }
    
    if( cnt % 2 ) ans |= 1<<(i-1);
    
  }
  
  cout<<ans<<endl;
  
}

signed main(){
  
  cin>>N;
  
  for(int i=0;i<N;i++) cin>>a[i];
  
  for(int i=0;i<N;i++) cin>>b[i];
  
  init();
  
  solve();
  
  return 0;
}
