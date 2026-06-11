#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
string S;
cin >> S;
for (int i = 0;i < 3;i++) {
    if (S.at(i) == '1') cout << 9;
    else if (S.at(i) == '9') cout << 1;
    else cout << S.at(i);
}
cout << endl;


return 0;
}
