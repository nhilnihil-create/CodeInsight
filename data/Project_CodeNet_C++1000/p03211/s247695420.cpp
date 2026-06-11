#include <iostream>
#include <string>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p = 1e9, ans = 1e9;
  string bigG;
  cin >> bigG;
  for(int i = 0;i < bigG.size() - 2;i++){
    pos = (bigG[i] - '0') * 100 + (bigG[i + 1] - '0') * 10 + (bigG[i + 2] - '0');
    if(abs(pos - 753) < p){
      p = abs(pos - 753);
      ans = pos;
    }
  }
  cout << p;
  return 0;
}
