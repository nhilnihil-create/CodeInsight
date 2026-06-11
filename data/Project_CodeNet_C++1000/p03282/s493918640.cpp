#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int index =0;
    int ans =0;
    for(int i=0;i<s.length();i++)
    {
        if( s[i]!='1')
        {
            ans = s[i] -'0';
            break;
        }
        else index++;
    }
    if( index>= k)
        cout<<1;
    else cout<<ans;
}