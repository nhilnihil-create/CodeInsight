#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, area;

    cin >> A >> B;

    if((A >= 2 && A <= 100) && (B >= 2 && B <= 100))
    {
        area = (A - 1) * (B - 1);
        printf("%d", area);
    }
    else
    {
        printf("Invalid Input");
    }

    return 0;
}
