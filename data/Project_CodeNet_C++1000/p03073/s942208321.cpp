#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char prev = s[0]; int cnt = 0;
    for (int i=1; i<s.length(); i++) {
        //cout << prev << ' ' << s[i] << ' ' << cnt << '\n';
        if (prev == s[i]) {
            cnt++;
            if (s[i] == '1') prev = '0';
            else prev = '1';
        }
        else prev = s[i];
    }
    cout << cnt << '\n';
    
    return 0;
}