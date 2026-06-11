#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

int a[20][20];

int dp[1<<20]; int memo[1<<20];
int same[1<<20];

int N;

int dfs(int bit){ 
  //１つだけビットが立っているときがベースケースなので注意
  if(memo[bit] != -1 ){ return memo[bit];}
 
  int flag = 0;
  
  for(int check = 0; check < N; check++){ 
    if( bit >> check & 1 ){ flag++;}
  }
  
  if( flag <= 1){ return memo[bit] = 0;}
 
  int res = 0;
  
  for(int i = bit; i > 0; i = (i-1)&bit){ // 3^Nで間に合わせる
    if( i == bit ){ continue;}
    
    int sub = i^bit;
    
    res = max(res, dfs(i)+same[sub]);
    
  }
  
  res = max(res, same[bit]);
  
  return memo[bit] = res;
  
}
    

signed main(void){
  
 
  cin >> N;
  
  for(int i = 0; i < N; i++){  
    for(int j = 0; j < N; j++){ cin >> a[i][j];
                              }
  }
  
  
  for(int i = 0;  i< (1<<20); i++){ memo[i] = -1;} 
  
  for(int i = 0; i < N; i++){ same[(1<<i)] = 0;} 
  //一つだけの時は当然0
  
  //次にsameを組み上げていく
  for(int bit = 0; bit < (1<<N); bit++){  //ここの計算量相当怪しい
    
    vector<int> vec; int sum = 0;
      
    for(int i = 0; i < N; i++){ 
      if( bit >> i & 1 ){ vec.push_back(i);}
    }
    

    int m = vec.size();
    
    for(int i = 0; i < m-1; i++){
      for(int j = i+1; j < m; j++){ 
        
        sum += a[vec[i]][vec[j]];
       
      }
    }

    same[bit] = sum;
  }
  
  
  if(true){cout << dfs((1<<N)-1) << endl;}
  
  return 0;
}