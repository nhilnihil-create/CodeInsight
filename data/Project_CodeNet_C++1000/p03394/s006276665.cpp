/*input
4
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll INF64=4e18;
const int INF=1e6+1;
const ll MOD=1e9+7;
const ld PI=2*acos(0);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
ll mult(ll a,ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=mult(res,a);
        a=mult(a,a);
        b>>=1;
    }
    return res;
}

// default code end
const ll maxn=1000005;
const ll maxlg=__lg(maxn)+2;
pii arr[maxn];
bool cmp(pii a,pii b){
    return a.f-a.s>b.f-b.s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    bool b[300010];
    vector<ll> v,ans(n);
    REP1(i,300000){
        if(i%2==0||i%3==0){
            v.push_back(i);
        }
    }
    if(n==3){
        cout<<"2 5 63"<<endl;
        return 0;
    }
    ll cnt=0;
    REP(i,n-2){
        ans[i]=v[i];
        b[v[i]]=true;
        cnt+=v[i];
    }
    for(int i=n-2;i<v.size();i++){
        if(cnt%2==0){
            if(v[i]%2==0){
                ans[n-2]=v[i];
                b[v[i]]=true;
                cnt+=v[i];
                break;
            }
        } else{
            if(v[i]%2==1){
                ans[n-2]=v[i];
                b[v[i]]=true;
                cnt+=v[i];
                break;
            }
        }
    }
    for(ll i:v){
        if(b[i]||i%2==1)continue;
        if(cnt%3==0){
            if(i%3==0){
                ans[n-1]=i;
                break;
            }
        }
        else if(cnt%3==1){
            if(i%3==2){
                ans[n-1]=i;
                break;
            }
        }
        else if(cnt%3==2){
            if(i%3==1){
                ans[n-1]=i;
                break;
            }
        }
    }
    REP(i,n){
        cout<<ans[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
    return 0;
}