#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a;
int b;

int main(){
  cin >> n;
  cin >> a;
  cin >> b;
  int sub;
  if(a>b) sub = a - b;
  if(a<=b) sub = b - a;
  sub = sub -1 ;
  if(sub%2==1) cout << "Alice" << endl;
  else cout << "Borys" << endl;
}
