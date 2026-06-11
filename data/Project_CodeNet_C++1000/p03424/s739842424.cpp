#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

int main() {
  int n;
  string s;
  cin >> n;

  for(int i = 1; i <= n; ++i){
    cin >> s;
    if(s == "Y") {cout << "Four" << endl; break;}
    if(i == n) { cout << "Three" << endl;}
  }
}
