#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n,d,x;
  cin >> n >> d >> x;
  
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<=100; j++){
      if(j*a[i]+1 <= d){
        x++;
      }
      else{
        break;
      }
    }
  }
  
  cout << x << endl;
  
	return 0;
}
