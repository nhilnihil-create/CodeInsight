#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int s;
  cin >> s;
  vector<int> vec;
  vec.push_back(s);
  int count = 1;
  while(1){
    count++;
    if (s % 2 == 0) s /= 2;
    else s = 3 * s + 1;
    if (binary_search(vec.begin(), vec.end(), s)) break;
    vec.push_back(s);
    sort(vec.begin(), vec.end());
  }
  cout << count << endl;
  
  return 0;
}