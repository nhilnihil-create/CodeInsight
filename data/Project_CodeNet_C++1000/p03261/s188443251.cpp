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
  set<string> s;
  string w;
  cin >> w;
  char c = w[w.size() - 1];
  s.insert(w);
  for(int i = 1; i < N; i++){
    string w;
    cin >> w;
    if(w[0] != c || s.count(w)){
      cout << "No" <<endl;
      return 0;
    }
    s.insert(w);
    c = w[w.size() - 1];
  }
  cout << "Yes" <<endl;
}
