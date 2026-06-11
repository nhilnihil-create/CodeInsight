#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int n,m,x;
  cin >> n >> m >> x;

  int a[m];
  for(int i = 0; i < m; ++i){
    cin >> a[i];
  }

  int resl=0,resr=0;
  for(int i = 0; i < x; ++i){
    for(int j = 0; j < m; ++j){
      if(a[j]==i){
        resl++;
      }
    }
  }

  for(int i = x; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(a[j]==i){
        resr++;
      }
    }
  }
  cout << min(resl,resr) << endl;
}

