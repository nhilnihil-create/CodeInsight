#include <bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
   /* int tt;
    cin >> tt;
    while (tt--){
      int N;
      cin >> N;
      int B[N];
      int sum = 0;
      int zero = 0;
      for(int i = 0; i < N; i++){
        cin >> B[i];
        sum += B[i];
        if(B[i]==0)zero++;
       
        
      }
      if(sum < 100){
        cout << "NO\n";
      }
      else{
        
        float diff = (float) sum - 100;
        N = N - zero;
        float check = 0.9*N;
        if(diff <= check)cout << "YES\n";
        else cout << "NO\n"; 
      }
      
    }*/
   // if(2 < 2.0)cout<<"jsis";
    //else cout<<"uwuw";
    
    int N;
    cin >> N;
    vector<long long> V(N);
    int cnt = 0;
    for(int i = 0; i < N; i++){
      long long x;
      cin >> x;
      V[i] = x;
     
      
    }
    for(long long x: V){
    //  int i = 2;
      if(x % 2 == 1) continue;
      
      while(x % 2 == 0){
        cnt++;
        x /= 2;
        
        
      }
    }
    cout << cnt;
}