#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    char b;
    cin >> b;

    map<char, char> mp;
    mp['A'] = 'T';
    mp['T'] = 'A';
    mp['C'] = 'G';
    mp['G'] = 'C';

    cout << mp[b] << '\n';
    return 0;
}
