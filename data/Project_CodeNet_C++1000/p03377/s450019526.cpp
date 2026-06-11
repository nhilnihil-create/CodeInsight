#include <iostream>
using namespace std;
int main()
{
    int a,b,x;
    cin>>a;
    cin>>b;
    cin>>x;
    if ((b>=x-a) && (x>=a))
        cout<<"YES";
    else 
        cout<<"NO";
}
