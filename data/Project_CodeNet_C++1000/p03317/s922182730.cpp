#include <bits/stdc++.h>
#define Keep_calmYou_are_still_learning ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
using namespace std;



int main()
{
   Keep_calmYou_are_still_learning;
    ll n , k;
    cin>>n>>k;
    for (ll x,i=0;i<n;i++)
        cin>>x;
    cout<<(n-3+k)/(k-1)<<'\n';

    return 0;
}
