#include <bits/stdc++.h>

int main(void)
{
    using namespace std;
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i < s.length(); ++i) {
        if (s.at(i) == '+')
            ++res;
        else
            --res;
    }
    cout << res << endl;
}