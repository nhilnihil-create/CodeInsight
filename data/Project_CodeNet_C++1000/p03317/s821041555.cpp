/*#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
   /* int tt;
    cin >> tt;
    while(tt--){
      int N,K;
      cin >> N >> K;
      int arr[N];
      int org = 0,less = 0;
      for(int i = 0; i < N; i++){
        cin >> arr[i];
        org += arr[i];
        if(arr[i] > K){
          less += arr[i];
          continue;
        }
        less += arr[i];
      }
      cout << org - less << "\n"; 
    }*/
      #include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    v[i] = x;
  }
  int flag = 0;
  int cnt = -1;
  for(int i = 0; i < n; i = i + k - 1){
    cnt++;
    if(i == n - 1)break;
    if(n - i - 1 < k - 1){
      flag = 1;
      break;
    }
    
  }
  if(flag)cnt++;
  cout << cnt;
    
}

