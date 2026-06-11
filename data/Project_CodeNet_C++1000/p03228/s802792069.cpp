#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  int a,b;
  cin >> a>>b>>n;
  for(int i=0;i<n;i++){
    if(a%2!=0){
      a--;
    }
        b += a/2;
    a -= a/2;
    swap(a,b);
  }
  if( n%2!=0){
    swap(a,b);
  }
    cout << a<<" " <<b;
}