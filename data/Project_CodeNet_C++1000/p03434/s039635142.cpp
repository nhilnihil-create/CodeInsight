#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int i,n,a[110],result=0;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
    result += a[i];
  }
  sort(a,a+n,greater<int>());
  for(i=1;i<n;i+=2){
    result -= 2*a[i];
  }
  cout << result << endl;
  return 0;
}