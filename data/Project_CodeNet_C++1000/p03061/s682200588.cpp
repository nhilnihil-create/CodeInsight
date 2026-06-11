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

    int n;cin>>n;

    int arr[n+1],frnt[n+1],bak[n+1];
    int gc=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        frnt[i]=__gcd(arr[i],gc);
        gc=frnt[i];
    }
    gc=0;
    for(int i=n-1;i>=0;i--)
    {
        bak[i]=__gcd(arr[i],gc);
        gc=bak[i];
    }
    int mx=-1;
    for(int i=0;i<n;i++){
        if(i==0)gc = bak[1];
        else if(i==n-1) gc = frnt[n-2];
        else gc = __gcd(frnt[i-1],bak[i+1]);
        mx = max(mx,gc);
    }

    cout<<mx<<endl;
    return 0;
}
