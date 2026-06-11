#include<bits/stdc++.h>
using namespace std;

int main(){
  int R,D,X;
  cin >> R >> D >> X;
  for(int i=0;i<10;i++){
    X=R*X-D;
    cout << X << endl;
  }
}