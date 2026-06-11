#include <bits/stdc++.h>
#define fio     ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define pi      3.14159265
#define ll      long long
#define repe    ll tc,cas=0;cin>>tc;while(tc--)
#define op      freopen("output.txt", "w", stdout);

#define maxn 10000010
using namespace std;

int main()
{
    fio;
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];


    ll sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]-b[i]>0)
            sum+=(a[i]-b[i]);
    }
    cout<<sum<<endl;

    return 0;
}
