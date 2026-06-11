#include <bits/stdc++.h>
using namespace std;
int main() {
int a,b;
cin >> a>> b;
int A = 0;

 for(int j = 1;j <b-a+1;j++){
A += j;
  }

cout << A-b <<endl;
}
