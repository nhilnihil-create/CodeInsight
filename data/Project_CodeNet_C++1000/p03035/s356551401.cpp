#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int a, b;
cin >> a >> b;
int ans;
if(a>=13) ans = b;
if(a>=6 && a<=12) ans = b /2;
if(a<=5) ans = 0;
cout << ans << endl;
return 0;
}