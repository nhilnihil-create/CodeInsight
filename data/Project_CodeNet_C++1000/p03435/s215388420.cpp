#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct edge {int to, cost; };
 
int main(){
  int c[3][3];
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin >> c[i][j];
    }
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<2; j++){
      if((c[i][j]-c[(i+1)%3][j])!=(c[i][j+1]-c[(i+1)%3][j+1])){
        cout << "No" << endl;
        return 0;
      }
      if((c[j][i]-c[j][(i+1)%3])!=(c[j+1][i]-c[j+1][(i+1)%3])){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
