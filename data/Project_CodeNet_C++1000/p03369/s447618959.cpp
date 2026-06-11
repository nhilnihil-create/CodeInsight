#include<bits/stdc++.h>
using namespace std;

string s;
int cnt;
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
        if(s[i]=='o')
            ++cnt;
    cout<<(700+cnt*100);
}
