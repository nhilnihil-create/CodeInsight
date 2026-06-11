#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string A ;
  string tg = "{3}";
  smatch m;
  cin >> A;
  for (int i = 0; i < A.size(); i++){
    regex re(A[i]+tg);
    if (regex_search(A, m, re)){
    cout << "Yes" << endl;
      return 0;
    }
  }
      cout << "No" << endl;

}