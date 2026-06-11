#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  int f = 0;
  rep(i, 0, 3){
    if(s[i] == 'o'){
      f++;
    }
  }
  
  cout << 700 + 100 * f << "\n";
}
