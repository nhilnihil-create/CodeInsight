#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int n;
  cin >> n;
  if(n % 2 == 0){
    int a = n / 2;
    cout << a * a << "\n";
    return 0;
  }
  int b = n / 2;
  int c = b + 1;
  cout << b * c << "\n";
}
