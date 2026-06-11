#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int A,B; cin >> A >> B;
  if(A <= 5) { 
    B = 0;
  } else if(A <= 12) { 
    B /= 2;
  } else {
    //
  }
  cout << B << endl;
}

