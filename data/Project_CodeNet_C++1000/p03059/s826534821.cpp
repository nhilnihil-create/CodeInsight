/*maksuda*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,b,t,n,c;
    cin>>x>>b>>t;
    if(t>=x){
        n=(t+0.5)/x;
        c=n*b;
    }
    else
   { c=0;}
    cout<<c<<endl;
}
