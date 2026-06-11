#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, d, x; cin >> n >> d >> x;
  vector<int> a(n);
  for(int &c : a) {
    cin >> c;
  }
  int allchocoes = 0;
  for(int c : a) {
    int dates = 1, eachchocoes = 0;
    while(dates <= d) {
      eachchocoes++;
      dates += c;
    }
    allchocoes += eachchocoes;
  }
  cout << allchocoes + x << endl;
}