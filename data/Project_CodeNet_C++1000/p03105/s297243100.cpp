#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x,y,z;
    while(cin>>x>>y>>z)
    {
        if(y>=x*z)
            cout<<z<<endl;
        else
            cout<<y/x<<endl;
    }
    return 0;
}
