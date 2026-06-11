#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v1(100010, 0), v2(100010, 0);
  rep(i, n){
    int v;
    cin >> v;
    if (i % 2 == 0) v1[v]++;
    else v2[v]++;
  }
  int a11,a12,a21,a22;
  int max11 = -1;
  int max12 = -1;
  int max21 = -1;
  int max22 = -1;
  rep(i, 100010){
    if (v1[i] > max11){
      a11 = i;
      max11 = v1[i];
    }
    if (v2[i] > max21){
      a21 = i;
      max21 = v2[i];
    }
  }
  rep(i, 100010){
    if (v1[i] > max12 && i != a11){
      a12 = i;
      max12 = v1[i];
    }
    if (v2[i] > max22 && i != a21){
      a22 = i;
      max22 = v2[i];
    }
  }
  
  int ans;
  if (a11 != a21){
    ans = n - max11 - max21;
  }
  else{
    ans = min(n-max11-max22, n-max12-max21);
  }
  cout << ans << endl;
  
  return 0;
}