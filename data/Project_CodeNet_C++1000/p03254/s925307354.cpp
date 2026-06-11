#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  int s=0;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  
  sort(a.begin(),a.end());
  
  long long as=0;
  for(int i=0; i<n; i++){
    as += a[i];
  }
  
  if(x <= as){
   for(int i=0; i<n; i++){
     if(x >= a[i]){
     x -= a[i];
     s++;
     }
     else{
       break;
     }
   }
  }
  
  if(x > as){
    s = n-1;
  }
  
  cout << s << endl;
	return 0;
}
