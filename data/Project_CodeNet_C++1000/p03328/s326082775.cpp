#include <iostream>;
#include <stdlib.h>;
using namespace std;
int main ()
{
    int a, b,t[999],s=0;
    cin>>a>>b;
    int sum=0,h[999];
    for (int i=1;i<=999;i++)
    {
        sum+=i;
        h[i-1]=sum;
    }
    cout<<h[abs(a-b)-1]-b<<endl;
    return 0;
}