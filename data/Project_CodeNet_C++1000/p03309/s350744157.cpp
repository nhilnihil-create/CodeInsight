#include <bits/stdc++.h> 
#include <iomanip>

using namespace std;
#define ll long long

ll INF = 1e18;

int main(){

    int n;
    cin>>n;

    ll sum = 0;
    vector<int>arr(n);
    vector<int>brr(n);

    for(int i = 0; i< n;i++)
    {
        cin>>arr[i];
        arr[i] -= (i+1); 
        brr[i] = arr[i];
    }

    sort(brr.begin(), brr.end());

    ll b, ans = 0;

    if( n%2 == 1)
    {
        b = brr[n/2];
        for(int i = 0; i< n;i++)
        {
            ans += (abs(arr[i] - b));
        }
    }
    else
    {
        b = brr[n/2];
        for(int i = 0; i< n;i++)
        {
            ans += (abs(arr[i] - b));
        }
        ll minVal = ans;
        b = brr[(n-1)/2];
        ans = 0;
        for(int i = 0; i< n;i++)
        {
            ans += (abs(arr[i] - b));
        }
        ans = min(minVal,ans);
    }

    cout<<ans<<endl;

    return 0;
}
