#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a,b,t;
    cin>>a>>b>>t;
    int time = t/a;
    int ans = time *b;
    cout<<ans<<endl;
    return 0;
}