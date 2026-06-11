#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<string> seat(N);
  int Left = 0;
  int Right = N;
  for (int i = 0; i < 20; i++) {
    if (i == 0) {
      cout << 0 << endl;
      cin >> seat[0];
      if (seat[0] == "Vacant") break;
    } else {
      int pivot = Left + (Right - Left) / 2;
      cout << pivot << endl;
      cin >> seat[pivot];
      if (seat[pivot] == "Vacant") break;
      if (seat[Left] == seat[pivot] && (pivot - Left) % 2 == 0) Left = pivot;
      else if (seat[Left] != seat[pivot] && (pivot - Left) % 2 != 0) Left = pivot;
      else Right = pivot;
    }
  }        
}