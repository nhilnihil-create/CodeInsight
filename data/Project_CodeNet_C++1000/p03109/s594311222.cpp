#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){ 
  string S;
  cin >> S;
  string Y(4,'0');
  for(int i = 0; i < 4; i++){
    Y.at(i) = S.at(i);
  }
  string M(2,'0');
  for(int i = 0; i < 2; i++){
    M.at(i) = S.at(i + 5);
  }
  int y = atoi(Y.c_str());
  int m = atoi(M.c_str());
  if(y < 2019) cout << "Heisei" << endl;
  else if(y = 2019 && m <= 4) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}
