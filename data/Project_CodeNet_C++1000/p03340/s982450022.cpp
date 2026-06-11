#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    int n;
    ll ans=0,z=0,sum=0,x=0;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<n; i++)
    {
        int pos=i+1;
        sum=arr[i];
        x=arr[i];
        z=1;
        if(arr[i]==0)
        {
            ll zero=1;
            int nxt=i;
            while(pos<n && arr[pos]==0)
            {
                nxt=pos;
                zero++;
                pos++;
            }
            z=0;
            while((pos<n && arr[pos]==0)|| (pos<n && (sum+arr[pos])==(x^arr[pos])))
            {
                z++;
                sum+=arr[pos];
                x^=arr[pos];
                pos++;
            }
            ans+=((zero*(zero+1))/2)+(z*zero);
            i=nxt;

        }
        else
        {
            while((pos<n && arr[pos]==0)|| (pos<n && (sum+arr[pos])==(x^arr[pos])))
            {
                z++;
                sum+=arr[pos];
                x^=arr[pos];
                pos++;
            }
            ans+=z;
        }

    }
    cout<<ans<<endl;



    return 0;
}
