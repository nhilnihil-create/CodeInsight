#include<iostream>
using namespace std;
int main(){
  int n,x; cin >> n >> x;
  if(n % 500 <= x)
    cout << "Yes";
  else
    cout << "No";
}
