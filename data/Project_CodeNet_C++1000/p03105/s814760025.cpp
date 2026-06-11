#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    if(B / C >= A)
        cout << C << "\n";
    else
        cout << B / A << "\n";

    return 0;
}
