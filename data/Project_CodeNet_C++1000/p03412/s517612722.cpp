#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int MAX_N = 4e5;
int A[MAX_N],B[MAX_N],a[MAX_N],b[MAX_N];

signed main(void){
  
  int N; cin >> N;
  for(int i = 0; i < N; i++){ cin >> A[i];}
  for(int i = 0; i < N; i++){ cin >> B[i];}
  
  int ans = 0;
  
  for(int bit = 0; bit < 40; bit++){ 
    
   int T = (1LL << (bit) );
    int mask = 2*T-1;
    
    for(int i = 0; i < N; i++){ 
      a[i] = (A[i] & mask);
      b[i] = (B[i] & mask);
      
    }
    
    
    sort(a,a+N);
    sort(b,b+N);
    
    int res = 0;
    
    for(int i = 0; i < N; i++){
      auto it1 = lower_bound(b,b+N,T-a[i]);
      auto it2 = lower_bound(b,b+N,2*T-a[i]);
      
      auto it3 = lower_bound(b,b+N,3*T-a[i]);
      auto it4 = lower_bound(b,b+N,4*T-a[i]);
      
      res += distance(it1,it2);
      res += distance(it3,it4);
      
      
    }
  
    res %= 2;
    
    ans += res*T;
    
  }
  
  cout << ans << endl;
  
  return 0;
  
}