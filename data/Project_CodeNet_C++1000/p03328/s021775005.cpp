#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;


int main() {
int64_t a,b;
cin >> a >> b;
int ans = 0;
for (int i = 1;i < b-a;i++) {
    ans +=i;
}
cout << ans - a << endl;


return 0;
}
