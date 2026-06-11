#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a;
    b=a;
    while(1){
    if(b%2==0 && b%a==0)
    {
        cout<<b<<endl;
        break;
    }
    else
        b++;

    }


    return 0;
}
