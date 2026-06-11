#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,h,w;
    cin>>n>>h>>w;
    if(h>n || w>n)
        cout<<0<<endl;
    else cout<<(n-h+1)*(n-w+1)<<endl;
    return 0;
}
