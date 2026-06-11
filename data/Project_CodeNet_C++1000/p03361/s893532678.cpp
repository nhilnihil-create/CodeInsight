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
      if(table.at(i).at(j)=='#'){
        int counter = 0;
        if (table.at(i-1).at(j)=='#') counter++;         
        if (table.at(i+1).at(j)=='#') counter++;         
        if (table.at(i).at(j-1)=='#') counter++;         
        if (table.at(i).at(j+1)=='#') counter++;         
          
//        cout << counter;
        if (counter == 0){
//          cout << i << " " << j << endl; 
          cout << "No" << endl;
          return 0;
        }
      }
    }
//    cout << endl;
  }
  cout << "Yes" << endl;
  return 0;
}