#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int s=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]=='+')
        s++;
        else
        s--;
    }
    cout<<s<<endl;
    return 0;
}