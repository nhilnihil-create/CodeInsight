#include <bits/stdc++.h>
using namespace std;

int main() {
 long long R,D,x;
 cin >> R >> D >> x;
  for(int i=0; i<10; i++){
     x =  x*R-D;
    cout <<  x << endl;
  }
}
