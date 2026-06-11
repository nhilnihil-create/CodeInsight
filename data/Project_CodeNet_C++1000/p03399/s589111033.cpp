#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
  int  A,B,C,D,a,b;
  cin >> A >> B >> C >> D;
  
  if(A < B) a = A;
  else a = B;
  
  if(C < D) b = C;
  else b = D;
  
  cout << a + b << endl;
}
