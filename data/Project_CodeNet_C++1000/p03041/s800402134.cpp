#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    s[k-1] = s[k-1] - 'A' + 'a';
    cout << s << endl;
    return 0;
}
