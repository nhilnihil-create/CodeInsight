#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
            int m;
            cin>>m;
            long long sum=0,ans=0;
            long long a[m+1],b[m+1];
            memset(b,0,sizeof(b));
            for(int j=1;j<=m;j++)
            {
                cin>>b[j];
                sum+=b[j];

            }
         //   cout<<sum<<endl;

               printf("%lld\n",sum-m);

}
