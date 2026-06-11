#include<iostream>
#include<vector>
using namespace std;
int main(void){
  int n;
  cin >> n;
  long ans = 0L;
  for(int i=0; i<n; ++i){
    int a;
    cin >> a;
    while(a%2==0){
      ans++;
      a/=2;
    }
  }
  cout << ans << endl;
  return 0;
}
  