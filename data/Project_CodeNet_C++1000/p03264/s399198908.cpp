#include <iostream>

using namespace std;

int main()
{
    int k,div;
    cin>>k;
    div=k/2;
    if(k%2==0)
    {
        cout<<div*div;
    }
    else
    {
        cout<<(div+1)*(div);
    }
}