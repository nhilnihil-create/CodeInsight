#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;
 
int main() {
  int A=0,B=0,C=0;
  for(int i=0; i<3; i++){
    char s;
    cin >> s;
    if(s=='a')A++;
    if(s=='b')B++;
    if(s=='c')C++;
  }
  if(A==1 && B==1 && C==1) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}