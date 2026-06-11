 #include <bits/stdc++.h>
using namespace std;
//vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値))
int main() {
  vector<vector<int>> c(3, vector<int>(3));
  for(int i = 0; i<3;i++){
    for(int j = 0; j<3;j++){
      cin >> c.at(i).at(j);
    }
  }
   if(c.at(0).at(0)-c.at(1).at(0) ==
      c.at(0).at(1)-c.at(1).at(1) &&
      c.at(0).at(1)-c.at(1).at(1) ==
      c.at(0).at(2)-c.at(1).at(2) &&
      c.at(1).at(0)-c.at(2).at(0) ==
      c.at(1).at(1)-c.at(2).at(1) &&
      c.at(1).at(2)-c.at(2).at(2) ==
      c.at(1).at(1)-c.at(2).at(1)){
     cout << "Yes" << endl;
   } else {
     cout << "No" << endl;
   }
                        
      
      
}