#include <iostream>

using namespace std;

int main()
{
    string b;
    cin>>b;
    if(b[0]=='A')
    {
        cout<<'T';
    }
    else if(b[0]=='T')
    {
        cout<<'A';
    }
    else if(b[0]=='C')
    {
        cout<<'G';
    }
    else
    {
        cout<<'C';
    }
}