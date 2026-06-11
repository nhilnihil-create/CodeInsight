#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[4];
    cin>>s;
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        if(s[i]=='2')
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
