
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    int D, N;
    cin >> D >> N;

    int D1[100];

    int D2[100];

    int D3[100];

    if (D == 0 && N < 100)
    {
        for (int i = 1; i <= 100; i++)
            D1[i] = i;
        cout << D1[N];
    }
    else if (D == 0 && N==100)
    {
       cout << "101";
    }
    else if (D == 1 && N < 100)
    {
        for (int i = 1; i < 100; i++)
            D2[i] = 100 * i;
        cout << D2[N];
    }
    else if (D == 1 && N == 100)
    {
       cout << 101*100;

    }
    else if (D == 2 && N < 100)
    {
        for (int i = 1; i < 100; i++)
            D3[i] = 10000*i;
        cout << D3[N];
    }
    else if (D == 2 && N == 100 )
    
       cout << 101*10000;

    return 0;
}
