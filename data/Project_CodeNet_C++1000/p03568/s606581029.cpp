#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int tot=1;
  int odds=1;
  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    tot *=3;
    if(a%2==1) odds*=1;
    else odds *=2;
  }
  cout << tot-odds << endl;
}