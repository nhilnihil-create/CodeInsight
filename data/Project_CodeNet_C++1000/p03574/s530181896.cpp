#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int H, W;
    cin >> H >> W;
    unsigned char S[H][W],A[H][W];
    int count;
  
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++)
      cin>> S[i][j];
  
    
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      count = 0;
      if(S[i][j] == '#'){//#だった場合
        cout << '#';
      }else{               //.だったとき
        for(int k=i-1; k<i+2; k++){  //周りの#をcountして代入
        	for(int l=j-1; l<j+2; l++){
              if(k >=0 && k<H && l >=0 && l<W)
            	if(S[k][l] == '#')
                  count++;
            }
        }
        cout << count;
      }    
    }
 cout << endl;
}
            
  }