#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  set< int > s;
  int count = 1;
  s.insert(n);
  while(1){
   if(n%2){
     n = (3*n) + 1;
     if(s.count(n) > 0){
       cout << count + 1 << '\n';
       return 0;
     }
     else s.insert(n);
   }
   else{
     n = n/2;
     if(s.count(n) > 0){
	  cout << count + 1 << '\n';
      return 0;
     }
     else s.insert(n);
   }
   count++;
  }
  return 0;
}