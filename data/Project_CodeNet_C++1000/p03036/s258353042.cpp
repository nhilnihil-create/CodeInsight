#include<bits/stdc++.h>

using namespace std;
int main()
{
    int r,d,x,i,res;

    cin>>r;
    cin>>d;
    cin>>x;

    for(i=0;i<10;i++){
        res=(r*x)-d;
        x=res;

        cout<<x<<endl;
    }

}
