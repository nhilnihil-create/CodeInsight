#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;
    string ans = count(s.begin(), s.end(), 'R') * 2 - n > 0 ? "Yes" : "No";
    cout << ans << endl;
    ;
}