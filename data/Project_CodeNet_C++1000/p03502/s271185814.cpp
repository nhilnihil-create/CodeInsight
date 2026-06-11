#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    unsigned n;
    int i,sum=0;
    char str[10];
    cin>>str;
    n=atoi(str);
    for(i=0;i<strlen(str);i++)
    {
        sum+=str[i]-48;
    }
    if(n%sum)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
    return 0;
}
