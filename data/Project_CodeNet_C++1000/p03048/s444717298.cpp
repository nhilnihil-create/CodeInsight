#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R,G,B,N,ans=0;
    cin>>R>>G>>B>>N;
    for(int i=0;i<=3000;i++)
    {
        for(int j=0;j<=3000;j++)
        {
            int v=(i*R)+(j*G);
            if(N>=v&&(N-v)%B==0)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;

}
