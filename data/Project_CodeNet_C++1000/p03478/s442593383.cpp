#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, a, b, sum = 0;
  cin >> n >> a >> b;
  vector<int> k(5, 0);
  for(int i = 1; i < n+1; i++) {
    k[0]++;
    for(int j = 0; j < 5; j++) {
      if(k[j] > 9) {
        k[j] = 0;
        k[j+1]++;
      } else {
        break;
      }
    }
    int ks = k[0]+k[1]+k[2]+k[3]+k[4];
    if(ks >= a && b >= ks) {
      sum += i;
    }
  }
  cout << sum << "\n";
}