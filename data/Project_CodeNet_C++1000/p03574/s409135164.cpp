#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H>>W;
  vector<vector<string>> data(H, vector<string>(W));
  
  for (int i=0; i<H; i++){
        string k;
        cin>>k;
        for (int j=0; j<W; j++){
            data.at(i).at(j)=k.at(j);
        }
    }
  vector<vector<int>> d(H, vector<int>(W,0));
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      if (data.at(i).at(j) == "#"){
        for (int a=i-1; a<i+2; a++){
          for (int b=j-1; b<j+2; b++){
            if(a<0 || a>=H || b<0 || b>=W){
            continue;
          }
            d.at(a).at(b)++;
          }
        }
      }
      
    }
  }
for (int i =0; i<H; i++){
        for(int j =0; j<W; j++){
          if(data.at(i).at(j)=="#")
          cout<<'#';

          else 
          cout<<d.at(i).at(j);          

          if (j==W-1){
          cout<<endl;
          }


        }
      }

    
}
