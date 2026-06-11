#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
  int r, D;

  vector<int>x(11,0);

  cin >> r >> D >> x[0];

  for( int i=0; i<=10; i++){
    x[i+1] = r*x[i] - D;
  }

  for( int i=1; i<=10; i++){
    cout << x[i] << endl;
  }
}
