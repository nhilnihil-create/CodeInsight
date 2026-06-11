#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int s, t;
  cin >> s >> t;
  if(t % s == 0) cout << s + t << "\n";
  else {
    cout << t - s << "\n";
  }
}