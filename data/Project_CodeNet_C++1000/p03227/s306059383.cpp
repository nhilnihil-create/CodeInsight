#include <bits/stdc++.h>
using namespace std;
int main()
{

    string A;
    cin >> A;
    if (A.size() == 2)
    {
        cout << A << endl;
    }
    else
    {
        reverse(A.begin(), A.end());
        cout << A << endl;
    }
}
