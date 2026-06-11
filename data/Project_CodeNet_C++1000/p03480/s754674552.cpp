#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
int main ()
{
    string c;
    cin>>c;
    int n=c.size();
    int a,b;
    a=0x3fffffff;
    b=0;
    for (int i=1; i<n; i++)
        if (c[i]!=c[i-1])
        {
            b=max(n-i,i);
            a=min(a,b);
        }
        if (a==0x3fffffff)
            cout<<n<<endl;
        else
    cout<<a<<endl;
    return 0;
}
