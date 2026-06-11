#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;


int main() {
int A,B;
cin >> A >> B;
int ans = max(A+B,max(A-B,A*B));
cout << ans << endl;


return 0;
}
