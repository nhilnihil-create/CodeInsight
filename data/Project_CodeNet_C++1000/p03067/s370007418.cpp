#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b,c;
    cin>>a>>b>>c;

    if(a-b<0)puts(a<c&&c<b?"Yes":"No");
    else puts(b<c&&c<a?"Yes":"No");

    return 0;
}
