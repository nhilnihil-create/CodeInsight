#include <bits/stdc++.h>
using namespace std;
 
int main() {

int a, b;
int ave, rem;

cin >> a >> b;

ave = (a + b) / 2;
rem = (a + b) % 2;

if(rem == 0){
  cout << ave << endl;
}
else if(rem == 1){
  cout << ave + 1 << endl;
}

}
