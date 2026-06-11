#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    string Y;
    cin >> X >> Y;
    if(X[0] == Y[2] && X[2] == Y[0]){
      if(X[1] == Y[1]){
        cout << "YES" << endl;
      }
      else {
        cout <<"NO"<<endl;
      }
    }
    else {
      cout << "NO" << endl;
    }
}

