#include <bits/stdc++.h>
using namespace std;
int INF = 100000000;
int main(){
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  int mxpos = 0;
  int mnpos = 0;
  for (int i = 0; i < N; i++){
    if (a[i] > a[mxpos]){
      mxpos = i;
    }
    if (a[i] < a[mnpos]){
      mnpos = i;
    }
  }
  if (a[mxpos] + a[mnpos] > 0){
    cout << N * 2 - 1 << endl;
    for (int i = 0; i < N; i++){
      cout << mxpos + 1 << ' ' << i + 1 << endl;
    }
    for (int i = 0; i < N - 1; i++){
      cout << i + 1 << ' ' << i + 2 << endl;
    }
  } else {
    cout << N * 2 - 1 << endl;
    for (int i = 0; i < N; i++){
      cout << mnpos + 1 << ' ' << i + 1 << endl;
    }
    for (int i = N - 2; i >= 0; i--){
      cout << i + 2 << ' ' << i + 1 << endl;
    }
  }
}