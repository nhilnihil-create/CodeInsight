#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define li          long
#define ll          long long
#define ull         unsigned long long
#define ff          first
#define ss          second
#define pii         pair<int,int>
#define pli         pair<li,li>
#define pll         pair<ll,ll>
#define pb          push_back
#define fo(i,k,n)   for(int i = k;i<n; i++)
#define ro(i,k,n)   for(int i = k; i>=n; i--)
#define fd(i,k,n,d) for(int i = k; i<n; i+=d)
#define tc          int t;cin>>t;while(t--)
#define all(v)      v.begin(),v.end()
#define inf         INT_MAX
#define ninf        INT_MIN
#define W(x)        cout<<x<<endl
#define WW(x,y)     cout<<x<<' '<<y<<endl;
#define in(x)       cin>>x
#define v(x)        vector<x>
#define int         long long
#define ar(x,y)       array<x,y>
const ll mod1 = 99844353;
const ll mod2 = 1e9+7;
template <class T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//****************************************************************************************************************************************//

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//*****************************************************************************************************************************************//

template<class T>
T power(T a,T b){
    T res = (T)1;
    while(b>0){
        if(b&1)res = res*a;
        b>>=1;
        a*=a;
    }
    return res;
}

template<class T>
T power(T a,T b,T m){
    T res = (T)1;
    a%=m;
    while(b>0){
        if(b&1)res = (res*a)%m;
        b>>=1;
        a = (a*a)%m;
    }
    return res;
}

//*****************************************************************************************************************************************//

struct dsu{
  map<int,int> pr,sz;
  dsu(){
    (this->pr).clear();
    (this->sz).clear();
  }
  void make(int x){
    pr[x] = x;
    sz[x] = 1;
  }
  int getpar(int x){
    if(pr[x] == x)return x;
    return pr[x] = getpar(pr[x]);
  }
  void merge(int x,int y){
    x = getpar(x);
    y = getpar(y);
    if(sz[x]<sz[y])swap(x,y);
    pr[y] = x;
    sz[x]+=sz[y];
    sz[y] = 0;
  }
};

//******************************************************************************************************************************************//
int n,k;
string s;
vector<int> ops((int)(1e5+5));
bool check(int x){
    int op = INT_MAX;
    int ans = 0;
    int i = 0;
    while(i<x){
        if(s[i] == '0'){
            ans+=1;
            int j = i+1;
            while(j<x && s[j] == '0')j++;
            i = j;
        }
        else i++;
    }
    op = min(op,ans);
    for(int i = x; i<n; i++){
        if(s[i-x] == '0' && s[i-x+1] == '1')ans-=1;
        if(s[i] == '0' && s[i-1] == '1')ans+=1;
        op = min(op,ans);
    }
    return op<=k;
}
void solve(){
    cin>>n>>k>>s;
    int l = 1,h = n;
    int ans = -1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }
        else h = mid-1;
    }
    cout<<(ans == -1?0:ans)<<"\n";
}

signed main(){
    fastio();
    int cs = 1;
    //cin>>cs;
    while(cs--){
        solve();
    }
}
