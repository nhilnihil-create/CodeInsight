#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,A,B;
    cin >>N>>A>>B;
    string res = "Alice";
    if((A - B - 1) % 2 == 0) res = "Borys";
    cout << res << endl;
    return 0;
}