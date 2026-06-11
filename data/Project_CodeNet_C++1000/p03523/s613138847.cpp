#include <bits/stdc++.h>
#define no { cout << "NO\n"; exit(0); }

using namespace std;

int main()
{
  //  freopen("input", "r", stdin);
    cin.sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;

    int i = 0;
    if(s[i] == 'A') ++i;
    if(i + 2 >= s.size() || s.substr(i, 3) != "KIH") no;
    i += 3;

    if(i<s.size() && s[i] == 'A') ++i;

    if(i==s.size() || s[i] != 'B') no
        else ++i;

    if(i<s.size() && s[i] == 'A') ++i;

    if(i==s.size() || s[i] != 'R') no
        else ++i;

    if(i<s.size() && s[i] == 'A') ++i;

    if(i != s.size()) no;

    cout<<"YES\n";

    return 0;
}
