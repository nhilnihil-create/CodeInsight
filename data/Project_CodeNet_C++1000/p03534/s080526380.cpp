#include<iostream>
#include<string>
#include<algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef int status;
typedef long long LL;
const int INF = int(1e9);
const int MAX = 400002;

char a[MAX];
int b[4] = {0} ;

int main()
{

    cin>>a;
    int len = strlen(a);

    for(int i = 0;i<len;i++)
    {
        b[a[i]-'a'+1]++;
    }
    int x,y,z;

    if(b[1]<=b[2]&&b[1]<=b[3])
    {
        x = b[1],y = b[2],z = b[3];
    }
    if(b[2]<=b[1]&&b[2]<=b[3])
    {
        x = b[2],y = b[1],z = b[3];
    }
    if(b[3]<=b[1]&&b[3]<=b[2])
    {
        x = b[3],y = b[2],z = b[1];
    }
    if(y-x<=1&&z-x<=1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }


    return 0;
}
