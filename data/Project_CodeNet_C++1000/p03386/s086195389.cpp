#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  long long a,b;
  int k;
  cin >> a >> b >> k;

  int count=0;
  for(int j=a; j <= b; ++j){
    if(j >= a && j <= b){
      if(count < k || count > b-a-k) cout << j << endl;
      count++;
    }
  }
}

