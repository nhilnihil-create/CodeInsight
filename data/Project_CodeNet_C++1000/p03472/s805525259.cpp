#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
  int n, h;
  cin >> n >> h;
  vector<long>a(n), b(n);
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  long i;
  for(i=0; i<n; i++){
    if(h<=0){
      cout << i;
      return 0;
    }
    if(b[i]<a[0])break;
    h-=b[i];
  }
  if(h<=0){
    cout << i;
    return 0;
  }
  if(h%a[0]==0)i+=h/a[0];
  else i+=h/a[0]+1;
  cout << i;
  return 0;
}