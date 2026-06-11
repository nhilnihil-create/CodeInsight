#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A, B, C; cin >> A >> C >> B;
    if ((A < B && B < C) || (A > B && B > C)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
