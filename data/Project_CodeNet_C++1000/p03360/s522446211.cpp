#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int maior, a1, a2;
    if (max(a, b) == a)
    {
        if (max(a, c) == a)
            maior = a, a1 = c, a2 = b;
        else
            maior = c, a1= a, a2 = b;
    } 
    else
    {
        if (max(b, c) == b)
            maior = b, a1 = a, a2 = c;
        else
            maior = c, a1 = a, a2 = b;
    }
    for (int i = 0; i < k; i++)
        maior *= 2;
    cout << maior+a1+a2 << endl;
    
}