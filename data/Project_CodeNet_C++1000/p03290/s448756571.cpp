#include<iostream>
using namespace std;

int main() {
  int D, G; cin >> D >> G;
  int P[D], C[D]; for (int i = 0; i < D; i++) cin >> P[i] >> C[i];
  int min_p = 1e+9;
  for (int b = 0; b < (1<<D); b++) {
    int p = 0;
    int point = 0;
    for (int i = 0; i < D; i++) {
      if (b & (1<<i)) {
        point += 100*(i+1)*P[i]+C[i];
        p += P[i];
      }
    }
    for (int i = D-1; i >= 0; i--) {
      if (!(b & (1<<i)) && point < G) {
        if (point + 100*(i+1)*(P[i]-1) <= G) {
          point += 100*(i+1)*(P[i]-1);
          p += P[i]-1;
        } else {
          p += (G-point+100*i)/(100*(i+1));
          point = G;
        }
      }
    }
    if (point >= G) {
      min_p = min(min_p, p);
    }
  }
  cout << min_p << endl;
}