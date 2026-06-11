#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a >= b + 2)
    {
        printf(":(\n");
    }
    else if (b >= a + 2)
    {
        printf(":(\n");
    }
    else
    {
        printf("Yay!\n");
    }

    return 0;
}