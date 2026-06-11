#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  char c,d;
  cin >> c >> d;
  if(c<d){
    cout << '<' << endl;
  }
  else if(c>d){
    cout << '>' << endl;
  }else{
    cout << '=' << endl;
  }
}