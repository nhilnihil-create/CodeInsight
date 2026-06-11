#include <bits/stdc++.h>
#define itn int

using namespace std;
typedef long long ll;


int main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  if(a[0]==a[1]&&a[0]==a[2]){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
