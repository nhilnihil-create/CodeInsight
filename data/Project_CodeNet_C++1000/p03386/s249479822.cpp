#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main() {

  int a, b, k;
  cin >> a >> b >> k;

  vector<int> vec;
  for(int i = 0; i < k; i++){
    if(a > b)
      break;
    vec.push_back(a);
    if(a < b) 
      vec.push_back(b);
    a++;
    b--;
  }
  sort(vec.begin(), vec.end());

  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
  }
}