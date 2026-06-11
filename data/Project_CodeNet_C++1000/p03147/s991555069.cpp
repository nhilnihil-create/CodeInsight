#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  vector<int> hana(N+1);
  hana[0]=0;
  int max = 0;
  for (int i = 1; i <= N; i++) {
    cin >> hana[i];
    if (max < hana[i]) {
      max = hana[i];
    }
  }
  int count = 0;
  for (int i = 1; i <= max; i++) {
    for (int j = 0; j < N; j++) {
      if(hana[j+1] >= i && hana[j] < i){
        count++;
      }
    }
  }
  cout << count <<endl;
}