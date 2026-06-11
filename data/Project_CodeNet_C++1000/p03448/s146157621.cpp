#include <bits/stdc++.h>
using namespace std;

int main() {
  int N_500,N_100,N_50,X;
  cin >> N_500;// >> endl;
  cin >> N_100;// >> endl;
  cin >> N_50;//  >> endl;
  cin >> X;// >> endl;
  
  int y;
  int ans;
  for(int i=0; i<N_500+1; i++) {
    for(int j=0; j<N_100+1; j++) {
      for(int k=0; k<N_50+1; k++) {
        y = 500*i + 100*j + 50*k;
        if (y == X) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}