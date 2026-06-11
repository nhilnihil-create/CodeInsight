#include<bits/stdc++.h>
typedef  long long ll;
using    namespace std;
#define  pb        push_back
#define  ff        first
#define  ss        second
#define  mk        make_pair
#define  all(v)    v.begin(),v.end()
#define  allr(v)   v.rbegin(),v.rend()
#define  sz        size()
#define  Tanmoy    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)

const int MAX=1e9+10;
const int MOD=1e9+7;
//for(ll i=0; i<n; i++)    **I Want To Be The Best**

int main()
{
    Tanmoy;

    ll n,k,x=1;
    cin>>n>>k;

    for(ll i=0; i<n; i++){
        if(x<k)x*=2;
        else x+=k;
    }
    cout<<x;

  return 0;
}

