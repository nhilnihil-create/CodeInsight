#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a;
  cin >> a;
  if(a >= 2800){
    cout << "AGC\n";
  }
  else if(a >= 1200){
    cout << "ARC\n";
  }
  else cout << "ABC\n";
}