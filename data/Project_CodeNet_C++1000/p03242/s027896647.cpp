#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string n;

  cin >> n;

  rep(i,3){
    if(n.at(i) == '1')
      n.at(i) = '9';
    else{
      n.at(i) = '1';
    }
  }

  cout << n;
}
