#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n,a,b;
    cin>>n>>a>>b;

    if(n==2)
        cout<<"Borys"<<endl;
    else{
        
        int diff=abs(a-b)+1;

        if(diff%2==0)
            cout<<"Borys"<<endl;
        else
            cout<<"Alice"<<endl;
        }

    return 0;
}
