#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s; cin >> s;
    int n = s.size();
    cout << ((15 - n) + count(s.begin(), s.end(),'o') >= 8 ? "YES" : "NO" ) << endl;
}