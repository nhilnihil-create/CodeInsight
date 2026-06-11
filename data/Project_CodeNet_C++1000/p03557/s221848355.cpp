#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll A[MAX],B[MAX],C[MAX],cs[MAX];
int n;
int bs_c(int val)
{
    int l=0,r=n-1,ans=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(C[mid]>val)
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return n-ans;
}
int bs_b(int val)
{
    int l=0,r=n-1,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(B[mid]>val)
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>A[i];
    for(int i=0; i<n; i++)
        cin>>B[i];
    for(int i=0; i<n; i++)
        cin>>C[i];
    sort(C,C+n);
    sort(B,B+n);
    for(int i=0; i<n; i++)
    {
        cs[i]=bs_c(B[i]);
    }
    for(int i=n-1; i>=0; i--)
        cs[i]+=cs[i+1];
    ll sum=0;
    for(int i=0; i<n; i++)
    {
        int cur=bs_b(A[i]);
        if(cur!=-1)
            sum+=cs[cur];
    }
    cout<<sum<<endl;


    return 0;
}
