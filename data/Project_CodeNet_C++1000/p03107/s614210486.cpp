#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    int br0=0,br1=0;
    cin >> s;
    for (int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
            br0++;
        else
            br1++;
    }
    cout << 2*min(br0,br1);
}
