#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int A, B; cin >> A >> B;

    if (!(B%A)) cout << A + B << endl;
    else cout << B - A << endl;    

    return 0;
}
