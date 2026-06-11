#include <bits/stdc++.h>

using namespace std;


int main() {
    string S;
    cin >> S;

    cout << S.substr(0, S.rfind("FESTIVAL")) << endl;
    return 0;
}