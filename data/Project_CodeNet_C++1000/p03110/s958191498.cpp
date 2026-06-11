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
  cin >> N;
  long double ans = 0;
  for(int i = 0; i < N; i++){
    long double x;
    string u;
    cin >> x >> u;
    if(u == "JPY"){
      ans += x; 
    } else{
      ans += x * 380000;
    }
  }
  cout << ans <<endl;
}
