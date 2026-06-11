#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
  int a,b;
  int n;
  cin >> n;
  for (a = 0; a < 100;a++){
    for (b = 0; b < 100;b++){
      if (4*a + 7*b == n){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;


  return 0; 
}

