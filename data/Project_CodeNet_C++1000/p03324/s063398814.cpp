#include<bits/stdc++.h>

using namespace std;

int main()
{
    int D,N,ans=1;
    cin>>D>>N;
    for(int i=1;i<=D;i++)
        {
            ans*=100;
        }
    if(N<100) cout<<ans*N<<endl;
    else cout<<ans*101<<endl;
    return 0;
}
