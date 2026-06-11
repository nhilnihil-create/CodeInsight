#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int n,x;
  cin >> n >> x;
  int min=1001;
  int res=0;
  for(int i = 0; i < n; ++i){
    int m[n];
    cin >> m[i];
    if(min > m[i]){
      min = m[i];
    }
    x -= m[i];
    res++;
  }

  res += x / min;
  
  cout << res << endl;
}

