#include <iostream>
using namespace std;
int main()
{
    int a,b,s;
    cin>>a>>b;
    s=a+b;
    if(s%2==0){
        s=s/2;
        cout<<s;
    }else
    {
        s=s/2;
        s++;
        cout<<s;
    }

    return 0;
}
