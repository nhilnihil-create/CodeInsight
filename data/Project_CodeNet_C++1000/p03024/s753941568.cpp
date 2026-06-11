#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int w = 0;

    for (const char &c : s)
        w += (c == 'o');

    w += (15 - s.size());


    if (w > 7) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}