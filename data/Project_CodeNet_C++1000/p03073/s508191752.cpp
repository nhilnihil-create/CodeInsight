#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,x=0,y=0;
    string str;
    cin>>str;
    for(i=0;str[i];i++)
    {
        if(i%2==0 && str[i]=='1')
            x++;
        else if(i%2==1 && str[i]=='0')
            x++;
    }
    for(i=0;str[i];i++)
    {
        if(i%2==0 && str[i]=='0')
            y++;
        else if(i%2==1 && str[i]=='1')
            y++;
    }
    cout<<min(x,y)<<endl;

    return  0;
}
