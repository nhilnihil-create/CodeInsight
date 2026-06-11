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
    cout << n << "\n";
  }
  else{
    cout << n * 2 << "\n";
  }
}