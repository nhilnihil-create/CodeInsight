#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pr pair<ll,ll>
#define loop(i,n) for(ll i=0 ; i<n ; ++i)
#define rep(i,x,n) for(ll i=x ; i<=n ; ++i)
#define iteloop(type,data,name,it) for(type<data>::iterator it=name.begin() ;it!=name.end() ; ++it)
using namespace std;
const ll N=2e2 + 5;
int n,k;
int main(){
    cin.sync_with_stdio(false), cin.tie(0) , cout.tie(0);
#ifndef ONLINE_JUDGE
   // freopen("in.txt", "rt" , stdin);
    // freopen("out.txt", "wt" , stdout);
#endif // ONLINE_JUDGE
    cin>>n>>k;
    cout<<n-k+1<<endl;
}