#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<limits>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    string x,y;
    cin>>x>>y;
    if (x>y)
    {
        cout<<'>'<<endl;
    }else if (x==y)
    {
        cout<<'='<<endl;
    }else
    {
        cout<<'<'<<endl;
    }
    
    
    

    return 0;
}