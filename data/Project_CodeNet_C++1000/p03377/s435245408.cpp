#include <iostream>
#include <fstream>

using namespace std;

int const NMAX = 1e6;
bool freq[1 + NMAX];

int main() {

  int n, m = 0, ans = 0;
  cin >> n >> m >> ans;
  if(n > ans || n + m < ans){
    cout << "NO";
  }else{
    cout << "YES";
  }
  return 0;
}
