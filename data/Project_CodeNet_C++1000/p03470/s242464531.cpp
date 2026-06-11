#include <iostream>
#include <string>

using namespace std;

int const NMAX = 100;
int freq[1 + NMAX];

int main() {

  int n, m, ans = 0, isB = 0;
  string p;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> m;
    freq[m]++;
    if(freq[m] == 1){
      ans++;
    }
  }
  cout << ans;
  return 0;
}
