#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    string n;
    cin >> n;

    cout << (((n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3])) ? "Yes" : "No") << endl;
    return 0;
}
