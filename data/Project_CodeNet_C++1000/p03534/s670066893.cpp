#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    int n = S.length();
    int a=0,b=0,c=0;
    for(int i=0; i<n; i++)
    {
        if(S[i]=='a')
            a++;
        else if (S[i] == 'b')
            b++;
        else if(S[i]=='c')
            c++;
    }
    if(max(max(a,b),c)-min(min(a,b),c)<=1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
