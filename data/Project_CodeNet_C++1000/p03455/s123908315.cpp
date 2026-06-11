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
  int c = a * b;
  if(c % 2 == 0){
    cout << "Even\n";
    return 0;
  }
  cout << "Odd\n";
}
  