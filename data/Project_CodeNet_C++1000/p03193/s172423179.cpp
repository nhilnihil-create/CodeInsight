#include<iostream>
using namespace std;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  
  int ans = 0;
  int c,d;
  for(int i = 0; i < n; i++){
    cin >> c >> d;
    if(c >= a && d >= b) ans++;
  }
  cout << ans << endl;
}
