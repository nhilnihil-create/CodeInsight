#include <iostream>

using namespace std;

int main()
{
    int r;
    scanf("%d", &r);
    if(r<=1199)
    {
        printf("ABC");
    }
    else if(r<=2799)
    {
        printf("ARC");
    }
    else
    {
        printf("AGC");
    }
    
}