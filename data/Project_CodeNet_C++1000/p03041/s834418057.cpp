#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    s[k - 1] = tolower(s[k - 1]);
    cout << s << endl;
}

