#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    int n;
    cin >> n;
    string s; cin >> s;
    cout << (count(s.begin(), s.end(), 'R') > count(s.begin(), s.end(), 'B') ? "Yes" : "No") << endl;
}