#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int rate;
    cin>>rate;
    if(rate<1200)
    {
        s = "ABC";
    }
    else if(rate<2800)
    {
        s = "ARC";
    }
    else
    {
        s = "AGC";
    }
    cout<<s<<'\n';
}