#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int A,B,C;
  cin >> A >> B >> C;

  if(A < C && C < B || A > C && C > B) cout << "Yes" << endl;
  else cout << "No" << endl;
}

