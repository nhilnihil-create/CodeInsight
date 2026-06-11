/*#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    int tt;
    cin >> tt;
    while(tt--){
      int N;
      cin >> N;
      long long sq = N * N;
      int start = 1;
      
      if( N % 2 == 1){
        for(int i = 0; i < N; i++)
        {
          for(int j = 0; j < N; j++){
            cout << start << " ";
            start += 1;
          }
          cout << "\n";
        }
      }
      else{
        for(int i = 1; i <= N; i++){
          if(i % 2 == 1){
            for(int i = 1; i <= N; i++){
              cout << start << " ";
              start += 1;
            }
            cout << "\n";
          
        }
        else{
          for(int i = 1; i <= N/2; i++){
            cout << start + 1 << " " << start << " ";
            start += 2;
          }
          cout << "\n";
        }
      }
      }
      
    }
}*/
 #include <bits/stdc++.h>
 #include <math.h>
 using namespace std;
 
 vector<int> store(16);
 void helper(){
   int num = 2;
   store[0] = 2;
   for(int i = 1; i <= 15; i++){
     num *= 2;
     store[i] = num;
   }
 }
 int main(){
   
   helper();
   int n,k;
   cin >> n >> k;
   
  if(n == 1 && k == 1){
  cout << 1;
  return 0;  
  }
  
  auto it = lower_bound(store.begin(),store.end(),k);
  int hi = it - store.begin() + 1;
  int lo = 1;
  int as = hi;
  int mid;
//  cout << start << endl;
  double sum = 0.0;
  if(n <= k)
  for(int i = 1; i <= k-1;i++){
    if(i > n)break;
    
    while(lo <= hi){
       mid = hi - (hi - lo)/2;
      
      if(i * pow(2,mid) == k)break;
      
      if(i * pow(2,mid) < k){
        lo = mid + 1;
        continue;
      }
      if(i * pow(2,mid) > k){
        if(i * pow(2,mid - 1) < k)break;
        else hi = mid - 1;
      }
    }
    lo = 1;
    hi = as;
    
   // if( n > k - 1)break;
    sum += (double)pow(0.5,mid);
  //  cout << mid << endl;
    
    
  }
  if(n > k){
    
    for(int i = 1; i <= k - 1; i++){
     // if(i >= k - 1)break
    
      while(lo <= hi){
       mid = hi - (hi - lo)/2;
      
      if(i * pow(2,mid) == k)break;
      
      if(i * pow(2,mid) < k){
        lo = mid + 1;
        continue;
      }
      if(i * pow(2,mid) > k){
        if(i * pow(2,mid - 1) < k)break;
        else hi = mid - 1;
      }
    }
    lo = 1;
    hi = as;
    
   // if( n > k - 1)break;
    sum += (double)pow(0.5,mid);
  //  cout << mid << endl;
  
      
    }
    for (int i = k; i <= n; i++){
      sum += 1.0;
    }
  }
  
  double tmp = (double)1/n;
 // cout << tmp << endl;
 // cout << sum << endl;
  double res = (double) sum * tmp;
  cout  << setprecision(12) << res;
  
  
  return 0;
  
 
 
 
 }