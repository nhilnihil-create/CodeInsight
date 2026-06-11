#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a[3];
  rep(i, 0, 3){
    cin >> a[i];
  }
  sort(a, a + 3);
  int b = a[1] + a[2] * 10;
  cout << a[0] + b << "\n";
}
