#include <iostream>

using namespace std;

char c[3][3];

void solve() 
{
    string s;
    s += c[0][0];
    s += c[1][1];
    s += c[2][2];

    cout << s << endl;
}

int main()
{
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) {
            c[i][j] = s[j];
        }
    }

    solve();

    return 0;
}