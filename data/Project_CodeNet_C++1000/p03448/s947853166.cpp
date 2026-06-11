/** author: __nishad__ **/
#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;
typedef vector<ll> vll ;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define precision(k) cout<<setprecision(k)<<fixed;
#define loop(i,a,b) for(ll i=(a);i<=(b);i++)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb push_back
#define mp make_pair
#define pi 3.14159265358979323
#define endl "\n"

int main()
{
    IOS;

    int n;

    int a, b, c, x, res=0, limit;
    cin>>a>>b>>c>>x;

    if(c<=0 && x%100!=0)
    {
        res = 0; limit=0;
    }
    else
        limit = x/50;

    loop(i, 0, a){
        loop(j, 0, b){
            loop(k, 0, c){
                if(i*500+j*100+k*50 == x)
                    res++;
            }
        }
    }

    cout<<res;


}




























