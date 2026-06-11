#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    set<char> t;
    char a, b, c;
    cin >> a >> b >> c;
    t.insert(a), t.insert(b), t.insert(c);

    cout << ((int)t.size() == 3 ? "Yes" : "No") << endl;

}