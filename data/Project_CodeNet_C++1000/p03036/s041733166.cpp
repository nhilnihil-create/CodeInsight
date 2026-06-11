#include <bits/stdc++.h>

#define int long long
#define fast_io(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ins insert
#define fi first
#define se second
#define _max max_element
#define _min min_element
#define tc(T) int T; cin>>T; while(T--)
#define q(q) int q; cin>>q; while(q--)

#define pi 3.1415926535897932384626433832
const int pinf=LLONG_MAX;
const int ninf=LLONG_MIN;
const int mod=1000000007;

using namespace std;

int32_t main()
{
    fast_io();

    //FILE *fptr1=freopen("../in.txt","r",stdin);
    //FILE *fptr2=freopen("out.txt","w",stdout);


    int r,d,a;
    cin>>r>>d>>a;

    vector <int> ans(11);
    ans[0]=a;
    loop(i,1,11)
    {
        ans[i]=ans[i-1]*r-d;
        cout<<ans[i]<< "\n";
    }



    return 0;
}
