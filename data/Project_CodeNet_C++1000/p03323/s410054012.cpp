#include<iostream>
using namespace std;

void solve(){
 int r,b;
  cin >> r >> b;
  int low = (r > b ? b : r);
  if(8-low >= abs(r-b)){
  	cout << "Yay!";
  }else{
	cout << ":(";
  }
}
int main(){
  solve();
return 0;
}