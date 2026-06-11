#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  string S[H];
  
  bool can = true;

  const int dx[4] = {1, 0, -1, 0};
  const int dy[4] = {0, 1, 0, -1};

  for(int i=0; i<H; i++){
     cin >> S[i];
    }

  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if (S[i][j]=='#'){
        	bool can_1 = true ;
        		for(int d=0; d<4; d++){
         		 const int ni = i + dy[d]; //列
         		 const int nj = j + dx[d]; //行
        		  if(ni < 0 || ni >= H) continue;
        		  if(nj < 0 || nj >= W) continue;
        		  if(S[ni][nj]=='#'){can_1 = false;}
      			  }
        if(can_1){can = false;}
       }
  }}
  if(can) cout << "Yes" << endl;
  else 	  cout << "No" << endl;
 return 0;
}