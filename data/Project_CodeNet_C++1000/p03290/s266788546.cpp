#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;

void change(int n, vector<int> &V){
 int i = 0;
  while(n > 0){
    int x;
    x = n%2;
    V[ i ] = x;
    n /= 2;
   i++;
  }
}

int main(){
  int D, G;
  cin >> D >> G;
  
  vector<vector<int>> V(10,  vector<int> (2));
  rep(i, D) rep(j, 2) cin >> V[i][j];
  
  int ans = 1000;
  
  for(int i = 0; i < pow(2, D); i++){
    int sum_score = 0;
    int sum_number = 0;
    vector<int> V2(D,0);
    
    change(i, V2);
    
   
    
    
    rep(j, D){
      if(V2[j] == 1){
        sum_score += 100*(j+1)*V[j][0]+V[j][1];
        sum_number += V[j][0];
      }
    }
    
    //cout <<  sum_score << endl;
    
    if(sum_score < G){
      for(int j = D-1; j>=0; j--){
        if(V2[j] == 0){
          int k = 0;
          
          //cout <<  V[j][0] << endl;
        
          while(sum_score < G && k < V[j][0]-1){
            sum_score += (j+1)*100;
            k++;
            
          }
          sum_number += k;
          break;
        }
      }
    }
    
    // cout <<  sum_score << endl;
    //cout <<  sum_number << endl;
    
    if(sum_score >= G){
      ans = min(ans, sum_number);
      
   //  cout << ans << endl;
    
      
    }
  }    
                          
 cout << ans << endl;
}
   
      

    

   
      
    
      
      
      
          
      
      
      
      
      