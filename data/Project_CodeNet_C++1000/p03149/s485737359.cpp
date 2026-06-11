#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int a[4];cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a,a+4);
  cout << ((a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) ? "YES":"NO") << endl;
}