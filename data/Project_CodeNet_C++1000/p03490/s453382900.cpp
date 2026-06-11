#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 8000;

string s;
int X, Y;
vector<int> A[2];
int dp[2][16001];
int tmp[16001];

void solve(){
  
  for(int idx=0;idx<2;idx++){
    
    dp[idx][M] = 1;
        
    for(int i=0;i<(int)A[idx].size();i++){
      
      int d = A[idx][i];
      
      memset( tmp, 0, sizeof(tmp) );
      
      for(int j=0;j<=16000;j++){
	
	if( dp[idx][j] ){
	  
	  if( !( idx == 0 && i == 0 ) && j - d >= 0 ) tmp[j-d] = 1;
	  if( j + d <= 16000 ) tmp[j+d] = 1;
	  
	}
	
      }
      
      for(int j=0;j<=16000;j++) dp[idx][j] = tmp[j];
	  
    }
    
  }
  
  if( dp[0][X] && dp[1][Y] ) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
}

signed main(){
  
  cin>>s;
  cin>>X>>Y;
  
  X += M;
  Y += M;
  
  int cnt = 0, idx = 0;
  
  s += 'T';
  
  for(int i=0;i<(int)s.size();i++){
    
    if( s[i] == 'F' ) cnt++;
    else{
      A[idx].push_back( cnt );
      cnt = 0;
      idx = !idx;
    }
    
  }
  
  solve();
  
  return 0;
}
