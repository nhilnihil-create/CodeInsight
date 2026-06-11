/** author: __nishad **/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;
typedef vector<ll> vll ;

#define all(v) (v).begin(),(v).end()
#define precision(k) cout<<setprecision(k)<<fixed;
#define loop(i,a) for(int i=0; i<a;i++)
#define loop2(i,a,b) for(int i=(a);i<=(b);++i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pi 3.14159265358979323

int main()
{
    IOS;

    ll n, m, x, y, p;
    vll v1, v2;

    cin>>n>>m>>x>>y;
    v1.pb(x);
    v2.pb(y);
    while(n--){
        cin>>p;
        v1.pb(p);
    }
    while(m--){
        cin>>p;
        v2.pb(p);
    }


    if(minv(v2) <= maxv(v1))
        cout<<"War";
    else
        cout<<"No War";

}

