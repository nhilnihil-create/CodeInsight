#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  vector<int> a(5);
  for(int i=0; i<5; i++){
  cin >> a[i];
  }
  
  int p = 0;
  int min = 10;
  for(int i=0; i<5; i++){
    if(a[i]%10 == 0){
      p += a[i]; 
    }
    else{
      if(a[i]%10 < min){
        min = a[i]%10;
      }
      p += 10 + a[i] - a[i]%10;
    }
  }
  
  p -= 10 - min;
  cout << p << endl;
	return 0;
}
