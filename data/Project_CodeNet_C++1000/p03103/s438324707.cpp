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
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll> >v;
    for(int i=0; i<n; i++)
    {
        ll a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(all(v));
    ll sum=0;
    for(int i=0; i<n; i++)
    {
        if(v[i].second<=m)
        {
            m-=v[i].second;
            sum+=v[i].first*v[i].second;
        }
        else
        {
            sum+=v[i].first*m;
            m=0;
            break;
        }
    }
    cout<<sum<<endl;

    return 0;
}
