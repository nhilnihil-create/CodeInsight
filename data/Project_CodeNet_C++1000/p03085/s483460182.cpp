#include <bits/stdc++.h>
using namespace std;
int main() {
  char b;
  cin >> b;
    if(b == 'A')b = 'T'; 
    else if(b == 'T')b = 'A';
    else if(b == 'C')b = 'G';
    else if(b == 'G')b = 'C';
  cout << b << endl;
}
