#include <bits/stdc++.h>
using namespace std;

int main(){
 int a,b,c; cin >> a >> b >>c;
 int d = a * 10 + b + c;
 int e = b * 10 + c + a;
 int f = c * 10 + a + b;
 cout << max(max(d,f),e);
}
