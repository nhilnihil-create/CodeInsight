#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  int cnt = 0;
  for(i=0;i<n;i++) cin >> a[i];
  for(i=0;i<n;i++){
    while(1){
      if(a[i]%2==0){
        a[i] /= 2;
        cnt++;
      }
      else break;
    }
  }
  cout << cnt << "\n";
  return 0;
}