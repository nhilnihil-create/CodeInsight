#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long s1=min(a,b);
    long long s2=min(c,d);
    cout<<s1+s2<<endl;
    return 0;
}