#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    int count = 0;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '+') count++;
        else count--;
    }
    cout << count << endl;
}
