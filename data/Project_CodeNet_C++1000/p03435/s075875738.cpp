#include <bits/stdc++.h>
using namespace std;

int main() {
   vector<vector<int>> c(3, vector<int>(3));
   for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
            int www; 
            cin >> www;
            c[i][j] = www;
      }
   }
   vector<int> x(3), y(3);
   x[0] = 0;
   for(int i = 0; i < 3; i++) y[i] = c[0][i] - x[0];
   for(int i = 0; i < 3; i++) x[i] = c[i][0] - y[0];
   
   bool aaa = true;
   for(int i = 0; i < 3; i++) {
   for (int j = 0; j < 3; j++) {
            if(x[i] + y[j] != c[i][j]) {
                  aaa = false;
            }
      }
   }
   
   if(aaa) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
