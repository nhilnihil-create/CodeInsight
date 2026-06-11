#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  int c = (a + b) / 2;
  int d = a - b;
  if(d % 2 == 0){
    cout << c << "\n";
    return 0;
  }
  cout << c + 1 << "\n";
}