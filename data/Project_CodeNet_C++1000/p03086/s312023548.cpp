#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int max = 0;
    int curr =0;
    for(int i=0;i<s.length() ;i++)
    {
        if( s[i] != 'A' && s[i] != 'C'&& s[i] != 'T' && s[i] !='G' )
        {
            curr =0;
        }
        else
        {
            curr++;
            if( curr> max)
                max = curr;
        }
    }
    cout<<max;
}