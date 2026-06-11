#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
  string S;
  cin >> S;
  int p = 700;
  
  for(int i = 0; i < 3; i++){
    if(S.at(i) == 'o') p += 100;
  }
  cout << p << endl;   
}
