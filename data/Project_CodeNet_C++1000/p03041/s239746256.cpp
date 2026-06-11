#include <iostream>
using namespace std;

int main ()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    k--;
    if (s[k] >= 'A' && s[k] <= 'Z') {
        s[k] = s[k] - 'A' + 'a';
    }
    cout << s;
}
