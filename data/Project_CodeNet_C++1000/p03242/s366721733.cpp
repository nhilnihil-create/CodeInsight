#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    char str[10];
    cin>>str;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='9')
        {
            cout<<"1";
        }
        else
        {
            cout<<"9";
        }
    }
    cout<<endl;
    return 0;
}
