#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> like(m);
  
  int k = 0;
  int a = 0;
  
  for(int i=1; i<=n; i++){
    cin >> k;
    for(int j=1; j<=k; j++){
      cin >> a;
      like[a-1]++;
      a = 0;
    }
    k = 0;
  }
  
  int count = 0;
  
  for(int i=0; i<m; i++){
    if(like[i] == n) count ++;
  }
    
  cout << count << endl;
	return 0;
}
