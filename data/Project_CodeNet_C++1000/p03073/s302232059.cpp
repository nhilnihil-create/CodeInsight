#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, ans1, ans2, c1, c2=1;
string s;
int main()
{
    IO
    cin>>s;
    n=s.size();
    for(int i=0; i<n; i++)
    {
        if(s[i]-'0'!=c1)
            ans1++;
        if(s[i]-'0'!=c2)
            ans2++;
        c1=1-c1;
        c2=1-c2;
    }
    cout<<min(ans1,ans2);
}
