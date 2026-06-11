#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int le=s.size();
    int n=le;
    for(int i=1;i<n;i++)
        if(s[i]!=s[i-1])
            le=min(le,max(n-i,i));
    cout<<le<<endl;
    return 0;
}
