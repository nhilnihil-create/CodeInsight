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
  int c = 0;
  rep(i, 0, 3){
    char a;
    cin >> a;
    if(a == '1'){
      c++;
    }
  }
  cout << c << "\n";
}