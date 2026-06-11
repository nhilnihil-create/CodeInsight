#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m=0;
    char c[6];
    for(int i=0;i<4;i++)
    {
        cin>>c[i];
        if(c[i]=='+') m++;
        else m--;
    }
    cout<<m<<endl;
    return 0;
}
