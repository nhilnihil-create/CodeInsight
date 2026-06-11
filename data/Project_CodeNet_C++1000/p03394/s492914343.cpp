#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;
    int nokori = N;
    if (N == 3)
    {
        cout << "2 5 63" << endl;
        return 0;
    }
    if (N == 4)
    {
        cout << "2 5 20 63" << endl;
        return 0;
    }

    if (nokori > 10000 && (nokori & 1))
    {
        cout << "15000 ";
        nokori--;
    }
    else if (nokori > 10000 && ~(nokori & 1))
    {
        cout << "15000 30000 ";
        nokori--;
        nokori--;
    }
    
    for (int i=1; i<=min(9999, nokori-2)/2; i++)
    {
        cout << i*3 << " " << 15000+i*3 << " ";
        nokori--;
        nokori--;
    }

    if (nokori & 1)
    {
        cout << "15002 15008 15014 ";
        nokori -= 3;
    }
    for (int i=0; i<nokori/2; i++)
    {
        cout << 6*i+2 << " " << 6*i+4 << " ";
    }
    return 0;
}