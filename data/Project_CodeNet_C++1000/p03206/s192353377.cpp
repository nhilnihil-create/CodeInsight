#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
    int D;
    cin >> D;
    int count = 25 - D;
    string s = "Christmas";
    rep(i,count)
    {
        s += " Eve";
    }
    cout << s;
}