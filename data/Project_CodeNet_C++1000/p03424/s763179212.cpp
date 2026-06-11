#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n, k = 0;
  string s;
  cin >> n;
  rep(i, n){
    cin >> s;
    if (s == "Y")
      k++;
  }
  if(k == 0)
    cout << "Three" << endl;
  else
    cout << "Four" << endl;
}