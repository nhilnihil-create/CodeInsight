#include <iostream>

using namespace std;

int main()
{
    string s;
    int n=0;
    cin>>s;
    for(int i=0; i<4; i++)
    {
        if(s[i]=='+')
        {
            n++;
        }
        else
        {
            n--;
        }
    }
    cout<<n;
}