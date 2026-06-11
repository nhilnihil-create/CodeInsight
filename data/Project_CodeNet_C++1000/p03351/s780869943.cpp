#include <bits/stdc++.h>
using namespace std;

int distance (int x,int y){
  if (x > y) return x-y;
  else return y-x;
}

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  int a_b = distance (a,b);
  int a_c = distance (a,c);
  int b_c = distance (b,c);
  
  if (a_c <= d) cout << "Yes" << endl;
  else if ((((a < b) && (b < c)) || ((a > c) && (b < c))) && ((a_b <= d) && (b_c <= d)))
    cout << "Yes" << endl;
  else cout << "No" << endl;
}