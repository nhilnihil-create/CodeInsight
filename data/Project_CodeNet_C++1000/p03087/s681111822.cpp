#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> count(n+1, 0);
  char prev = '?';
  rep(i, n){
    int x = 0;
    if (prev == 'A' && s[i] == 'C') x = 1;
    count[i+1] = count[i] + x;
    prev = s[i];
  }
  
  rep(i, q){
    int l, r;
    cin >> l >> r;
    cout << count[r] - count[l] << endl;
  }
  
  return 0;
}