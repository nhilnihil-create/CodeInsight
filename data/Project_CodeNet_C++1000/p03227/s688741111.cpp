#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin>>s;

    if(s.size()==2)cout<<s;
    else for(int i=2;i>=0;i--)cout<<s[i];

    return 0;
}
