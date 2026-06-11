#include <iostream>
using namespace std;
int main()
{
    int R;
    cin >> R;
    if (R < 1200)
    {
        printf("ABC");
    }
    else if (R >= 1200 && R < 2800)
    {
        printf("ARC");
    }
    else
    {
        printf("AGC");
    }
}