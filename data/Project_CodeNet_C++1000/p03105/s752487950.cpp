#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        cout<<min(b/a,c)<<endl;
    }
}
