#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;


int main(){
  int N;
  cin >> N;
  int ans = 100000;
  int k = N/9;
  
  for(int i = 0; i <= k; i++){
    int x = i;//９の倍数で支払う額
    int y = (N-9*x)/6;//６の倍数で支払う額
    int z = N-9*x-6*y;//１で支払う額
    int countx = 0;
    int county = 0;
    while(x>0){
      countx += x%9;
      x /= 9;
    }
    while(y>0){
      county += y%6;
      y /= 6;
    }
    ans = min(ans, countx+county+z);
  }


    
      
    
  
  
  cout << ans << endl;
}
   
      
    
      