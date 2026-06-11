#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
        int A,B,C;
        cin>>A>>B>>C;
        if(A>B)
                printf("0");
        else if(B/A<=C)
                printf("%d",B/A);
        else
                printf("%d",C);
        return 0;
}
