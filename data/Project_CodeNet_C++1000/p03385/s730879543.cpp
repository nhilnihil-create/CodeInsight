#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;


int main() {
string S;
cin >> S;
sort(S.begin(),S.end());
if (S.at(0) == 'a' && S.at(1) == 'b' && S.at(2) == 'c') {
    cout << "Yes" << endl;
} else cout << "No" << endl;



return 0;
}
