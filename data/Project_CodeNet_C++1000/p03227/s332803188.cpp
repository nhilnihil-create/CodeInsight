#include <stdio.h>

int main()
{
    char S[4],temp;
    scanf("%s",S);

    int i = 0,length;
    while (S[i])
    {
        length = i;
        i++;
    }
    if (length == 2)temp = S[0],S[0] = S[2],S[2] = temp; 
    printf("%s",S);
}
