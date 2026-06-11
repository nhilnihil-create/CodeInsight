#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    char C; cin >> C;
    switch (C)
    {
        case 'A':
            cout << "T\n";
            break;
        case 'T':
            cout << "A\n";
            break;
        case 'G':
            cout << "C\n";
            break;
        case 'C':
            cout << "G\n";
            break;
    }
}