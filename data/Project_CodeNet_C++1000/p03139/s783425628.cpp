#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
int n, a, b, z;
cin >> n >> a >> b;
if (a <= b)
cout << a << " ";
else
cout << b << " ";
z = a + b;
if (z - n > 0)
cout << z - n;
else
cout << 0;
return 0;
}