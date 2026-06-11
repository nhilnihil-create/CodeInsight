#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C;
    cin >> A>>B>>C;
    vector<int>vec(200000,0);
    for(int k=0;k<=C;k++){
      for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            ++vec.at(500*i+100*j+50*k);
          }
        }
    }
   int X;
    cin >>X;
  cout <<vec.at(X)<<endl;
} 