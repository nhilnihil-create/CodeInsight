#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int n,m,i,flag=0;
    char s[110],t[110],str[120];
    cin>>s;
    cin>>t;
    n=strlen(s);
    m=strlen(t);
    if(n==m)
    {
    strcpy(str,s);
    for(i=0;i<n;i++)
    {
        //cout<<str<<endl;
        if(!(strcmp(str,t)))
        {
            flag=1;
            break;
        }
        strcpy(s,str);
        str[0]=s[n-1];
        str[1]='\0';
        strcat(str,s);
        str[n]='\0';

    }

    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
    }
    else
        cout<<"No";


    return 0;
}
