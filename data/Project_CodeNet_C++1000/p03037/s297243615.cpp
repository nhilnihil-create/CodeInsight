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


    int n,m;
    cin>>n>>m;

    vector <pair <int,int> > a(m);

    loop(i,0,m)
    {
        cin>>a[i].first>>a[i].second;
    }

    sort(all(a));

    int l=a[0].first;
    int r=a[0].second;

    loop(i,1,m)
    {
        if(a[i].first<=r)
        {
            l=a[i].first;
            r=min(r,a[i].second);
        }
        else
        {
            cout<< "0";
            return 0;
        }
    }

    cout<<r-l+1;



    return 0;
}
