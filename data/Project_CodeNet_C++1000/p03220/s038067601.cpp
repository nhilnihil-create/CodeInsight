#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int N;
  long double T, A;
  cin >> N >> T >> A;
  long double minn = 99999999;
  int ans = 0;
  for(int i = 0; i < N; i++){
    long double x;
    cin >> x;
    long double tmp = T - x * 0.006;
    if(abs(A-tmp) < minn){
    ans = i + 1;
    minn = abs(A - tmp);
    }
  }
  cout << ans <<endl;
}
