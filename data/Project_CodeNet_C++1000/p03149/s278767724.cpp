#include<bits/stdc++.h>
using namespace std;

int main(){
  int a = 0, b = 0, c = 0, d = 0;
  int n[4];
  cin >> n[0] >> n[1] >> n[2] >> n[3];
  for(int i = 0; i < 4; i++){
    if(n[i] == 1) a++;
    else if(n[i] == 9) b++;
    else if(n[i] == 7) c++;
    else if(n[i] == 4) d++;
  }
  if(a == 1 && b == 1 && c == 1 && d == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
}