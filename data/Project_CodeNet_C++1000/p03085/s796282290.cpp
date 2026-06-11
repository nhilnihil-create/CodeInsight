#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    switch (s[0])
    {
        case 'A':
            putchar('T');
            break;

        case 'C':
            putchar('G');
            break;

        case 'G':
            putchar('C');
            break;

        case 'T':
            putchar('A');
            break;
    }
    return 0;
}