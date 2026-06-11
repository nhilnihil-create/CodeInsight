#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l1, l2, r1, r2;
    cin >> l1 >> l2 >> r1 >> r2;

    if ((l1 + l2) > (r1 + r2))
        cout << "Left" << endl;
    else if ((l1 + l2) < (r1 + r2))
        cout << "Right" << endl;
    else
        cout << "Balanced" << endl;
    return 0;
}
