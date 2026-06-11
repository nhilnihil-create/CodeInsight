#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==0)
        cout<<min(b,c)<<endl;
    else
        cout<<min(b/a,c)<<endl;
}
