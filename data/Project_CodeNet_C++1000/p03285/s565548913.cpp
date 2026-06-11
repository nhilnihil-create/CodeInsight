#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  string available="No";
  for (int i=0; i<=25; i++) {
    for (int j=0; j<15; j++) {
      if (4*i + 7*j == N) {
        available = "Yes";
        break;
      }
    }
    if (available == "Yes") break;
  }
  cout << available << endl;
}