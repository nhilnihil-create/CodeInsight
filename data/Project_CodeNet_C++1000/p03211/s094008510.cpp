#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int ans = INT_MAX;
    for(int i=0;i<=s.length()-3;i++)
    {
        string temp = s.substr(i,3);
        int temp1 = stoi(temp);
        ans = min( ans , abs(temp1 - 753));
    }
    cout<<ans;
}