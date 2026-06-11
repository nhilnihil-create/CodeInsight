#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;


int main() {
int N;
cin >> N;
int ans;
if (N % 2 == 0)  ans = N;
else ans = 2*N;

cout << ans << endl;

return 0;
}
