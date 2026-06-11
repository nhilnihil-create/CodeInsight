#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1000000007;
const long long inf = 1e18;

int n;
vector<ld> v;
vector<pair<ld,ld>> t;

ld fm(ld x){
    ld ansv=inf;
    for(int i=0;i<n+2;i++){
        ld l=t[i].fi;
        l*=1.00000;
        ld r=t[i].se;
        r*=1.00000;
        ld sa;
        if(x>=0 && x<=l){
            sa=v[i]+(l-x)*1.000000;
        }
        else if(x>=l && x<=r){
            sa=v[i];
            sa*=1.000000;
        }
        else{
            sa=v[i]+(x-r)*1.000000;
        }
        if(sa<ansv)
            ansv=sa;
    }
    return ansv;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    ld count=0.00000;
    t.pb(mp(0.00000,0.00000));
    for(int i=0;i<n;i++){
        ld k;
        cin>>k;
        t.pb(mp(count,count+k));
        count+=k;
    }
    t.pb(mp(count,count));
    v.pb(0.000);
    for(int i=0;i<n;i++){
        ld k;
        cin>>k;
        v.pb(k);
    }
    v.pb(0.000);
    vector<ld> ans;
    for(ld i=0;i<=count;i+=0.500000){
        ld k=fm(i);
        ans.pb(k);
    }
    ld countans=0.00000;
    for(int i=0;i<ans.size()-1;i++){
        ld sa=0.25000*(ans[i]+ans[i+1]);
        countans+=sa;
    }
    cout<<setprecision(9)<<countans<<endl;

    return 0;
}
