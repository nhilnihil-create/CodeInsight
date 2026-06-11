#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> str(H,vector<char>(W));
  for(int i=0;i<H;i++){
  	for(int j=0;j<W;j++){
    	cin >> str.at(i).at(j);
    }
  }
  vector<vector<int>> num(H+2,vector<int>(W+2,0));
  for(int i=0;i<H;i++){
  	for(int j=0;j<W;j++){
    	if(str.at(i).at(j)=='#') {
          num.at(i).at(j)++;
          num.at(i).at(j+1)++;
          num.at(i).at(j+2)++;
          num.at(i+1).at(j)++;
          num.at(i+1).at(j+2)++;
          num.at(i+2).at(j)++;
          num.at(i+2).at(j+1)++;
          num.at(i+2).at(j+2)++;
    }
  }
  }
  for(int i=0;i<H;i++){
  	for(int j=0;j<W;j++){
    	if(str.at(i).at(j)=='.') cout <<num.at(i+1).at(j+1);
      	else cout << '#';
    }
  cout << endl;
  }
}