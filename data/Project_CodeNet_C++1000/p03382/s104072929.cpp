#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
  int N;
  
  int a[100010],b[100010];
  
  cin >> N;
  
 
  for(int i=0;i<N;i++)
  cin >> a[i] ;
    
   sort(a,a+N,greater<int>());
  
  long long int bmin = 2e9;
  int ans ;
  
  for(int i=1;i<N;i++){
    if(abs(a[i]-(a[0]+1)/2) > bmin ){
      continue;
    }
    else{
      bmin = abs(a[i]-(a[0]+1)/2);
      
      ans = a[i];
    }
  }
  
  cout << a[0] << " " << ans << endl;
}
      
              
  
  
