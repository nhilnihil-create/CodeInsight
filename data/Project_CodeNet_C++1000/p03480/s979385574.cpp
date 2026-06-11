#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    char a[100005];
    scanf("%s",a);
    int l=strlen(a);
    int i;
    bool flag;
    int op=l;
    int max1;
    for( i=0; i<l-1; i++)
    {
        if(a[i]!=a[i+1])
        {
            if(i+1>=l-i-1)
            {
                flag=1;
                max1=i+1;
            }
            else
            {
                flag=0;
                max1=l-i-1;
            }
            op=op>max1?max1:op;
            if(flag)
            {

                for(int j=0; j<max1; j++)
                {
                    if(a[j]=='1')
                        a[j]=='0';
                    else
                        a[j]=='1';
                }
            }
            else
            {
                for(int j=i+1; j<l; j++)
                {
                    if(a[j]=='1')
                        a[j]=='0';
                    else
                        a[j]=='1';
                }
            }
        }
    }
    printf("%d\n",op);
    return 0;
}
