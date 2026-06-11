#include<bits/stdc++.h>
using namespace std;
int main(){
  int H=0, W=0, count=0;
  cin >> H >> W;
  vector<string>s(H);
  for(int i=0;i<H;i++){
    cin >> s.at(i);
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s.at(i).at(j) == '#'){
        cout << "#";
      }else{
      for(int k=-1;k<2;k++){
        for(int l=-1;l<2;l++){
          if(i+k<H && i+k>=0 && j+l<W  && j+l>=0){
            if(s.at(i+k).at(j+l)=='#'){
              count++;
              }//if
            }//if
          }//for l
        }//for k
        cout << count;
        count=0;
      }//else
    }//for j
    cout << endl;//for iの中
  }//for i
}//main