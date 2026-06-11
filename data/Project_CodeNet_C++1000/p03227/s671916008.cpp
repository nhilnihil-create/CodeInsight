#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int size_s = s.size();
    if (size_s == 3)
    {
        for (int i = size_s - 1; i >= 0; i--)
        {
            cout << s[i];
        }
        cout << endl;
    }
    else
    {
        cout << s << endl;
    }
    
}