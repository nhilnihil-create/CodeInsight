#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
 char a[9];
  rep(i, 0, 9){
    cin >> a[i];
  }
  cout << a[0] << a[4] << a[8] << "\n";
}