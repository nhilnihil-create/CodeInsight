#include <bits/stdc++.h>
using namespace std;

int N;
int x[100], y[100], h[100];
int ansx, ansy, ansh;

/* return
    bool success or not.
    int value of ansh.
 */
pair<bool, int> simulate(int cx, int cy){
  int calcH=0;
  for (int i = 0; i < N; i++) { 
    if (h[i] > 0){
      calcH=h[i]+abs(x[i]-cx)+abs(y[i]-cy);
      break;
    }
  }

  for (int i = 0; i < N; i++) {
    if ( max(calcH - abs(x[i]-cx) - abs(y[i]-cy ), 0) != h[i] ){
        return {false, -1};
    }
  }
  return {true, calcH};
}

void solve(){

  for (int cx = 0; cx <= 100; cx++) {
    for (int cy = 0; cy <= 100; cy++) {
      pair<bool, int> result = simulate(cx, cy);
      if(result.first){
        ansx=cx;
        ansy=cy;
        ansh=result.second;
        return;
      }
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
  }

  solve();

  cout << ansx << " " << ansy << " " << ansh << endl;

  return 0;
}