#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){    
  char b,c;
  cin >> b;
  if(b == 'A') c = 'T';
  else if(b == 'T') c = 'A';
  else if(b == 'C') c = 'G';
  else c ='C';
  
  cout << c << endl;
}
