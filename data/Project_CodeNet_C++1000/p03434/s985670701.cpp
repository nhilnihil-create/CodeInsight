#include <bits/stdc++.h>
using namespace std;

#define FLASH ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"

int32_t main()
{
    FLASH;
    int n; 
    cin>>n;
    int arr[n];
    int sal=0,sbob=0,x;
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    sort(arr, arr+n, greater<int>());
    for(int i=0;i<n;i++)
    {
        if(i%2==0) sal+=arr[i];
        else sbob+=arr[i];
    }
    cout<<abs(sal-sbob)<<endl;
}