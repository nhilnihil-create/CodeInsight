#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    if( s.length() != a+b+1)
    {
        cout<<"No";
    } else
    {
        if( s[a] != '-' )
        {
            cout<<"No";
            return 0;
        }
        else
        {
            for(int i=0;i<s.length();i++)
            {
                if( i!= a && (s[i] >'9' || s[i] <'0') ) {
                    cout << "No";
                    return 0;
                }
            }
            cout<<"Yes";
        }
    }
}