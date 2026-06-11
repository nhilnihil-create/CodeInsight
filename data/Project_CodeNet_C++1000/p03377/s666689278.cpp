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
  int a, b, x;
  cin >> a >> b >> x;
  if(a <= x){
    if(x <= a + b){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}