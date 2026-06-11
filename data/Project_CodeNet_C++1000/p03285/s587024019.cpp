/** author: __nishad__ **/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;
typedef vector<ll> vll ;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define precision(k) cout<<setprecision(k)<<fixed;
#define loop(i,a) for(int i=0; i<a;i++)
#define loop2(i,a,b) for(int i=(a);i<=(b);++i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb push_back
#define pi 3.14159265358979323
#define endl "\n"

int main()
{
    IOS;

    ll n;
    cin>>n;

    for(int i=0; i<=n/4+1; i++){
        for(int j=0; j<=n/7+1; j++){
            if((i*4+j*7) == n){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
}

