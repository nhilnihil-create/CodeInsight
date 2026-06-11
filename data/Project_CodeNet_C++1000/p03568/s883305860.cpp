#include<iostream>
using namespace std;
int main(){
  int ans = 1;
  int n; cin >> n;
  int odd = 1;
  for(int i = 0; i < n; i++){
    ans *= 3;
    int a; cin >> a;
    if(a % 2 == 0) odd *= 2;
  }
  cout << ans - odd;
}