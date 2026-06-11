#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    if(s[5] == '0' && s[6] - '0' <= 4)
        cout << "Heisei";
    else
        cout << "TBD";

    return 0;
}
