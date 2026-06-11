#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  int rt = 0;
  cin >> A >> B;
  for (int i = A; i <= B; i++) {
    string str = to_string(i);
    string copy(str);
    reverse(str.begin(), str.end());
    if (copy == str){
    rt++;}
  }
 cout << rt << endl;
}