#include<cstdio>
#include<cstring>

int main()
{
    int n, A, B;
    int num;
    int p1, p2, p3;
    p1 = p2 = p3 = 0;
    scanf("%d", &n);
    scanf("%d %d", &A, &B);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &num);
        if(num<=A)
            p1++;
        else 
            if(num>B)
                p3++;
            else
                p2++;
    }
    if(p1<=p2 && p1<=p3)
        printf("%d", p1);
    else 
        if(p2<=p3)
        printf("%d", p2);
        else
            printf("%d", p3);
    return 0;
}