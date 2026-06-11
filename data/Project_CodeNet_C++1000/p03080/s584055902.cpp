#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main(){
  int N; cin >> N;
  string S; cin >> S;

  int R = 0, B = 0;
  for (int i = 0; i < S.length(); i++){
    if (S[i] == 'R') R ++;
    else B++;
  }

  if (R > B) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
