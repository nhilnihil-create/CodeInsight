#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string A, B;
  cin >> A >> B;

  if (A < B){
    cout << "<" << endl;
  }
  else if (A > B)
  {
    cout << ">" << endl;
  }
  else
  {
    cout << "=" << endl;
  }
  
  
}