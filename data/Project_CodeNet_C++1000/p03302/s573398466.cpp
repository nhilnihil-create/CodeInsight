#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    if (x+y==15) cout<<"+";
    else if (x*y==15) cout<<"*";
    else cout<<"x";
    return 0;
}