#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    string keyence = "keyence";
    int head = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (head >= keyence.size() || S.at(i) != keyence.at(head))
        {
            break;
        }
        head++;
    }
    int tail = keyence.size() - 1;
    for (int i = S.size() - 1; i >= 0; i--)
    {
        if (tail < 0 || S.at(i) != keyence.at(tail))
        {
            break;
        }
        tail--;
    }
    if (tail < head)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}