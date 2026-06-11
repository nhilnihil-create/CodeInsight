#include <iostream>
using namespace std;

string s;
int ans;

void solve()
{
    ans = 700;

    for (int i = 0; i < 3; i++) {
        char c = s[i];
        if (c == 'o') ans += 100;
    }
}

int main()
{
    cin >> s;

    solve();

    cout << ans << endl;

    return 0;
}