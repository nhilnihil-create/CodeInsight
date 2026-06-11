#include <bits/stdc++.h>
using namespace std;

int main(){

int n = 0, a = 0, b = 0; cin >> n >> a >> b;

int x =  abs (a-b);

if (x >= 1) x-=1;
else x = 0;

if (x%2 == 0) cout << "Borys" << endl;
else cout << "Alice" << endl;


return 0;
}
