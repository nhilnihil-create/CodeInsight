#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll x=0,t=3;
    string ss;
    while(t--){
        string s;
        getline(cin,s);
        ss.push_back(s[x++]);
    }
    printf("%s\n", ss.c_str());
    return 0;
}