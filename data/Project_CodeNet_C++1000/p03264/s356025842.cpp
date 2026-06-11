#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int K;
cin >> K;
int ans;
if (K % 2 == 0) {
    ans = (K/2) * (K/2);
} else {
    ans = (K/2) * (K/2+1);
}
cout << ans << endl;


return 0;
}
