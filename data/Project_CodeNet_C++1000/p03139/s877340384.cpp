#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
  int n,a,b,max,min;
  cin >> n;
  cin >> a;
  cin >> b;
  max = 0;
  min = 0;

  max = std::min({a,b});
  min = std::max({0,(a+b)-n});

  cout << max << " " << min << endl;
  return 0;

}
