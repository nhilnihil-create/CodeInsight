#include <bits/stdc++.h>
using namespace std;

int d[110];

int main(){
  int n; cin >> n;
  for(int i = 2; i <= n; i++){
    int tmp = i;
    for(int j = 2; j <= i; j++){
      while(tmp % j == 0){
        d[j]++;
        tmp /= j;
      }
    }
  }
  int ans = 0;
  vector<int> k(5); //2, 4, 14, 24, 74
  for(int i = 2; i <= n; i++){
    if(d[i] >= 2) k.at(0)++;
    if(d[i] >= 4) k.at(1)++;
    if(d[i] >= 14) k.at(2)++;
    if(d[i] >= 24) k.at(3)++;
    if(d[i] >= 74) k.at(4)++;
  }
  ans += k[4] + k[3]*(k[0]-1) + k[2]*(k[1]-1);
  ans += k[1]*(k[1]-1)*(k[0]-2)/2;
  cout << ans << endl;
}
                                     
    
        
        
      
        
        
      