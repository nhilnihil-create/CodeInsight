#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;


int main() {
int a,b,c,d;
cin >> a >> b >> c >> d;
if (abs(a-c) <= d) cout << "Yes" << endl;
else if (abs(b-a) <= d && abs(b-c) <= d) cout << "Yes" << endl;
else cout << "No" << endl;



return 0;
}
