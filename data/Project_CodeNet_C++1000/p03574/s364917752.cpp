#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int H, W; cin >> H >> W;
  vector<vector<char>> table(H+2, vector<char>(W+2,'.')); 
  for (int i=1; i<H+1; i++){
    for (int j=1; j<W+1; j++){
      cin >> table.at(i).at(j);
    }
  }

  for (int i=1; i<H+1; i++){
    for (int j=1; j<W+1; j++){
      if(table.at(i).at(j)=='#')  cout << table.at(i).at(j);
      else{
        int counter = 0;
        for(int k=-1; k<2; k++){
          for(int l=-1; l<2; l++){
            if(table.at(i+k).at(j+l)=='#') counter++;
          }
        }
        cout << counter;
      }
    }
    cout << endl;
  }
 

}