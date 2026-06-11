#include <iostream>
#include <fstream>

using namespace std;

int const NMAX = 1e6;
bool freq[1 + NMAX];

int main() {

  int n, m = 0, ans = 0;
  cin >> n;ans+= n;cin >> n;ans+= n;
  cin >> n;m+= n;cin >> n;m+= n;
  if(ans > m){
    cout << "Left";
  }else if(ans == m){
    cout << "Balanced";
  }else{
    cout << "Right";
  }
  return 0;
}
