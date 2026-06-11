#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    if( s[0] != 'A')
    {
        cout<<"WA";
        return 0;
    }
    int count =0;
    for(int i=2;i<=s.length() -2;i++)
    {
        if(s[i] =='C' )
            count++;

    }
    if( count != 1)
    {
        cout<<"WA";
        return 0;
    }
    for(int i=0;i<s.length();i++)
    {
        if( s[i] <96 && (s[i]!='A' && s[i] != 'C'))
        {
            cout<<"WA";
            return 0;
        }
    }
    cout<<"AC";
}