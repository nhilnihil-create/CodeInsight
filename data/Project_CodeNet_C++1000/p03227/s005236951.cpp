#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int main()
{
    string a;
    cin>>a;

    int b=a.length();
    if(b==2)
        cout<<a<<endl;
    if(b==3)
    {
        reverse(a.begin(),a.end());
        cout<<a<<endl;
    }
    return 0;
}
