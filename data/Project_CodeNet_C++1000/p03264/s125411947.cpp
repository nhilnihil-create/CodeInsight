#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;

    int np = k / 2;
    int nip = k - np;

    cout << np * nip << endl;
}