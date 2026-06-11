#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=2005;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
int main()
{
    std::ios::sync_with_stdio(false);
    int n,sum=0;
    cin>>n;
    bitset<N*N> bi;
    bi[0]=1;
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        sum+=c;
        bi|=bi<<c;
    }
    for(int i=(sum+1)/2;i<=sum;i++)
    {
        if(bi[i])
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
