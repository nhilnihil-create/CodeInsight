#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    int ans = (B/A);
    if(ans>C)
    {
        cout<<C<<endl;
        return 0;
    }
    else 
    {
       cout<<ans<<endl;
        return 0;
    }
}
