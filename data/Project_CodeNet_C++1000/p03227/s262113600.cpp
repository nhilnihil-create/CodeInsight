#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s; cin >> s;
    if((int)s.size() == 3)reverse(s.begin(), s.end());
    cout << s << endl;
}