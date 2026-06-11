#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n,m;
  cin >> n >> m;
  
  vector<vector<ll>>rl(m,vector<ll>(2));
  for(int i=0; i<m; i++){
    cin >> rl[i][1] >> rl[i][0];
  }
  
  sort(rl.begin(),rl.end());
  
  ll count = 1;
  ll cut = rl[0][0]-1;
  for(int i=0; i<m; i++){
    if(rl[i][1]>cut){
      count++; 
      cut = rl[i][0]-1;
    }
  }
  cout << count << endl;
  
}
  
  
  
  
