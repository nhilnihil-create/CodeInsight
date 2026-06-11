/// إِنَّ مَعَ الْعُسْرِ يُسْرًا
/// لَا أَبْرَحُ حَتَّىٰ أَبْلُغَ

#include <bits/stdc++.h>
#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld  double

#define HabdModeActive ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define S second
#define F first
#define PI acos(-1)
#define MAX 5000005
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);


int main() {
    HabdModeActive
    int n;
    cin>>n;
    ll arr[n+2];
    ll gcdL[n+2],gcdR[n+2];
    for(int i=0 ;i<n;i++)
    {
        cin>>arr[i];
    }
    gcdL[0] = arr[0];
    for(int i=1 ; i<n; i++)
    {
        gcdL[i] = __gcd(arr[i],gcdL[i-1]);
    }
    gcdR[n-1] = arr[n-1];
    for(int i=n-2; i>=0 ; i--)
    {
        gcdR[i] = __gcd(arr[i],gcdR[i+1]);
    }
    ll mx = 0;
    for(int i= 0 ;i<n ; i++)
    {
        if(i==0)
        {
            mx = max(mx,gcdR[i+1]);
        }
        else if(i==n-1)
        {
            mx = max(mx,gcdL[i-1]);
        }
        else{
            mx = max(mx,__gcd(gcdL[i-1],gcdR[i+1]));
        }
    }
    cout<<mx;

    return 0;
}
