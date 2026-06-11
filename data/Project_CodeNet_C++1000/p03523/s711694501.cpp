#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    string S;
    cin >> S;
    if (S[0] != 'A')
    {
        S.insert(0, "A");
    }
    if (S.size() < 5)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (S[4] != 'A')
    {
        S.insert(4, "A");
    }
    if (S.size() < 6)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (S[6] != 'A')
    {
        S.insert(6, "A");
    }
    if (S.size() < 8)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (S[8] != 'A')
    {
        S.insert(8, "A");
    }
    if (S != "AKIHABARA")
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
