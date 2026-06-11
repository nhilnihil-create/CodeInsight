#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    if(n%2 != 0){
        n *= 2;
    };
    cout << n << endl;
  return 0;
}