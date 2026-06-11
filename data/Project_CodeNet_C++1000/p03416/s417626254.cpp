#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

bool isPalindrome(int x) {
    string s = to_string(x);
    string v;
    for (int i = s.length()-1; i>=0; i--) {
        v += s[i];
    }
    for (int i=0; i<s.length(); i++) {
        if (s[i] != v[i]) return false;
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i=a; i<=b; i++) {
        if (isPalindrome(i)) cnt++;
    }
    cout << cnt << '\n';
    
    return 0;
}