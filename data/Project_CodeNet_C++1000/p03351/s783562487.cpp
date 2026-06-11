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
  if(a == b && b == c){
    cout << "Yes\n";
    return 0;
  }
  int e = a - c;
  if(e < 0){
    e = e * (-1);
  }
  if(d >= e){
    cout << "Yes\n";
    return 0;
  }
  int f = a - b, g = b - c;
  if(f < 0){
    f = f * (-1);
  }
  if(g < 0){
    g = g * (-1);
  }
  if(d >= f && d >= g){
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}
  