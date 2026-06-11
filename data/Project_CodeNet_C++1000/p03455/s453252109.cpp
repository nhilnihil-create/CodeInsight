#include <bits/stdc++.h>
using namespace std;

int main() {
int a,b;
  cin >> a >> b;
  int A=a%2;
  int B=b%2;
  if(A*B==1){
    cout << "Odd" << endl;
  }
    else{
      cout << "Even" << endl;
    }
}
