#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  string s;cin >> s;
  rep(i,3){
    if(s[i] == '1')cout<<"9";
    if(s[i] == '9')cout<<"1";
  }
}