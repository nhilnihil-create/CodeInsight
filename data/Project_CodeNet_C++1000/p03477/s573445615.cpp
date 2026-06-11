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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a += b;
  c += d;
  if(a == c){
    cout << "Balanced\n";
    return 0;
  }
  if(a < c){
    cout << "Right\n";
    return 0;
  }
  cout << "Left\n";
}
  