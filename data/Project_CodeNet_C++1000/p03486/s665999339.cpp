#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // s` < t` の辞書順になればよい
    // つまりsは昇順にソート、tは降順にソートして比較すればよい

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    string t;
    cin >> t;
    sort(t.begin(), t.end(), greater<char>());

    if (s < t) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}