#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> vec(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>vec.at(i).at(j);
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(vec.at(i).at(j)!='#'){
        int c=0;
        if(i-1>=0&&j-1>=0){
         if(vec.at(i-1).at(j-1)=='#'){
          c++;
         }
        }
        if(i-1>=0){
         if(vec.at(i-1).at(j)=='#'){
          c++;
         }
        }
        if(i-1>=0&&j+1<W){
         if(vec.at(i-1).at(j+1)=='#'){
          c++;
          }
         }
        if(j-1>=0){
         if(vec.at(i).at(j-1)=='#'){
          c++;
          }
        }
        if(j+1<W){
         if(vec.at(i).at(j+1)=='#'){
          c++;
          }
        }
        if(i+1<H&&j-1>=0){
         if(vec.at(i+1).at(j-1)=='#'){
          c++;
          }
        }
        if(i+1<H){
         if(vec.at(i+1).at(j)=='#'){
          c++;
          }
        }
        if(i+1<H&&j+1<W){
         if(vec.at(i+1).at(j+1)=='#'){
          c++;
         }
        }
      cout<<c;
     }
     else{
       cout<<'#';
     }
    }
    cout<<endl;
  }
}