#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
 int a,b,c,d,e,k;
 cin >> a >> b >> c >> d >> e >> k;

 if(abs(a - b) <= k && abs(a - c) <= k && abs(a - d) <= k && abs(a - e) <= k && abs(b - c) <= k && abs(b - d) <= k && abs(b - e) <= k && abs(c - d) <= k && abs(c - e) <= k && abs(d - e) <= k) {
     cout << "Yay!"; return 0;
 }

 cout << ":(";
    return 0;
}