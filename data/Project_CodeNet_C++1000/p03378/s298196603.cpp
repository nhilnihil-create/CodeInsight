#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  int x;
  cin >> x;
  vector<int> v(m);
  for(int i=0; i<m; i++){
    cin >> v[i];
  }
  int sma,big;
  sma = 0;
  big = 0;
  for(int i=0; i<m; i++){
    if(v[i] > x){
      big++;
    }
    else{
      sma++;
    }
  }
  
  cout << min(big,sma) << endl;
  
	return 0;
}
