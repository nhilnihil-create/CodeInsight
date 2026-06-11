#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string fi = s.substr(0, 2);
    string en = s.substr(2, 2);
    int f = stoi(fi);
    int e = stoi(en);
    if(f != 0 && f < 13 && e != 0 && e < 13)
    {
        cout << "AMBIGUOUS\n";
    }
    else if(f != 0 && f < 13)
    {
        cout << "MMYY\n";
    }
    else if(e != 0 && e < 13)
    {
        cout << "YYMM\n";
    }
    else
    {
        cout << "NA\n";
    }

    return 0;
}
