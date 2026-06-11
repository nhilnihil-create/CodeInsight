#include <iostream>
using namespace std;

int main() {
  int N, ways=0; cin >> N;
  for (int i=0; i<N/4+1; i++) {
    for (int j=0; j<N/7+1; j++) {
      if (4*i+7*j==N) ways++;
    }
  }
  if (ways>0) cout << "Yes" << endl;
  else cout << "No" << endl;
}