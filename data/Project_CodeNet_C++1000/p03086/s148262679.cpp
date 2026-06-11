#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> vec;
  int times;
  bool stopper = true;
  string a, c;
  cin >> a;
  c = "";
  times = a.size();
  for(int i = 0; i < times; i++) {
    if(a[i] == 'A'||a[i] == 'G'||a[i] == 'C'||a[i] == 'T'){
      c += a[i];
      stopper = true;
      }
    else if (stopper){
      vec.push_back(c);
      stopper = false;
      c = "";
    }
  }
  vec.push_back(c);
  int b = 0;
  int vec_size = vec.size();
  for(auto& x:vec) {
    if (x.size() > b) {
      b = x.size();
    }
  }
  cout << b << endl;
}