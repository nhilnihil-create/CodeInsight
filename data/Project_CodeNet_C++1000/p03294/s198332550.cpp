#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  cout << accumulate(a.begin(), a.end(), 0) -n << endl;
  return 0;
}

