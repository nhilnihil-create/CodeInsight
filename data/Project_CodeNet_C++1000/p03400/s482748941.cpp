#include <bits/stdc++.h>
using namespace std;

int main() {
 int n, d, x;
 cin >> n >> d >> x;
 vector<int> A(n);
 for(int i = 0; i < n; i++){
    cin >> A.at(i);
  }
  int chocolate = 0;
  for(int i = 0; i < n; i++){
    int c = 0;
    int b = 0;
  while(1){
    c = A.at(i)*b + 1;
    if(c > d) break;
    b++;
    chocolate++;
  }
  }
   cout << chocolate + x << endl;
}
