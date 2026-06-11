#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int H,W;
  cin >> H >> W;
  
  char a[H][W];
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
		cin >> a[i][j];
    }
  }

 for(int i=0; i<H; i++){
	for(int j=0; j<W; j++){
		if(a[i][j]=='.'){
          int count=0;
          for(int k=i-1; k<=i+1; k++){
            for(int l=j-1; l<=j+1; l++){
              if(k<0 || k>=H || l<0 || l>=W)
                continue;
              if(a[k][l]=='#')
                count++;
            }
          }
          
          a[i][j]='0' + count;
        }
    }
 }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
		cout << a[i][j];
    }
    cout << endl;
  }
}