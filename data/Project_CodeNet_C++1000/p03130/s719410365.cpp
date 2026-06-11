#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c[5] = {0};
    for (int i = 0; i < 6; i++)
    {
        int ab;
        cin >> ab;
        c[ab]++;
    }
    
    int i;
    for (i = 1; i <= 4; i++)
    {
        if(c[i] >= 3)break;
    }
    
    if(i == 5)cout << "YES" << endl;
    else cout << "NO" << endl;
}