#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  int c = a * b;
  if(c % 2 == 0){
    cout << "No\n";
  }
  else{
    cout << "Yes\n";
  }
}