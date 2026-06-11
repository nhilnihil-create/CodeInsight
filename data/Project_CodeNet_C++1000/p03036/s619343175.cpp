#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll r,d,x;cin>>r>>d>>x;
    ll a[11];
    a[0]=x;
    for(int i=1;i<=10;i++){
        a[i]=r*a[i-1]-d;
        cout<<a[i]<<"\n";
    }
}
