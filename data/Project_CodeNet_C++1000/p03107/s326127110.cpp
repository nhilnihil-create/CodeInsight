#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int z=0,o=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]=='0')
            z++;
        else
            o++;
    }
    cout<<(2*min(z,o))<<endl;
    return 0;
}
