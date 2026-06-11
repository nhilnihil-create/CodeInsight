#include<bits/stdc++.h>

using namespace std;

int main()
{
    int D,N;
    cin>>D>>N;
    if(D==0 && N%100==0) cout<<N+1<<endl;
    else if(D==0) cout<<N<<endl;
    else
    {
        for(int i=0;i<D;i++)
        {
            if(N==100) N=N*101;
            else N=N*100;
        }
        cout<<N<<endl;
    }
    return 0;
}
