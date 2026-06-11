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
    int64_t a,b,c;
    cin>>a>>b>>c;
    if (c<=b+a)
    {
        cout<<c+b<<endl;
    }else
    {
        cout<<2*b+a+1<<endl;
    }
    
    

    return 0;
}