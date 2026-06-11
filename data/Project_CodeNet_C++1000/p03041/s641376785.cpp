#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    s[b-1]+=32;
    cout<<s;
    return 0;
}
