
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    string S;
    cin >> S;

    int t = 0;

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '+')
            t++;
        else if (S[i] == '-')
            t--;
    }

    cout << t;

    return 0;
}
