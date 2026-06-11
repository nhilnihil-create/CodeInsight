#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int a,b,c,d;
  cin >> a >> c >> b >> d;
  if(max(a-b,b-a)<=d) cout << "Yes" << endl;
  else if(max(a-c,c-a)<=d&&max(b-c,c-b)<=d) cout << "Yes" << endl;
  else cout << "No" << endl;
}