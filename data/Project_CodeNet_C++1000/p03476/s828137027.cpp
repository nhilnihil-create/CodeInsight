#include <iostream>

using namespace std;

int main(){
  int Q;
  cin >> Q;
  int l[Q], r[Q], e[100001], a[100001];
  for (int i = 0; i < Q; i++){
    cin >> l[i] >> r[i];
  }
  e[1] = 0;
  for (int i = 2; i < 100001; i++){
    e[i] = 1;
  }
  

  for (int i = 2; i <= 100000; i++) {
    if (e[i] == 1) {
      for (int j = 2 * i; j <= 100000; j++) {
        if (j % i == 0) {
          e[j] = 0;
        }
      }
    }
  }

  int s = 0;
  for (int i = 1; i <= 100000; i++){
    if (e[i] == 1 && e[(i+1)/2] == 1) s++;
    a[i] = s;
  }

  for (int i = 0; i < Q; i++){
    printf("%d\n", a[r[i]] - a[l[i]-1]);
  }
}
