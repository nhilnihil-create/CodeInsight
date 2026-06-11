#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<ll,ll>
#define se second
#define ld long double
#define mod 1000000007
#define popcount __builtin_popcountll
#define PI acos(-1.0)
using namespace std;
ll a[200010];

vector<ll>v;
ll cum[200015];
ll get_sum(int l, int r){
    if(l==0)return cum[r];
    return cum[r]-cum[l-1];
}


ll get_ans(int l,int r,int mid){
    ll lf = get_sum(l,mid);
    ll rt = get_sum(mid+1,r);
    if(mid+1>r)return 1e18;
    return abs(lf-rt);
}

ii get(int st, int en){
    if (st == en) return {0,1e18};

    // cout<<"ST EN "<<st<<"  "<<en<<endl;
    ll l = st, r = en, lt, rt;
    for (int i=1;i<=169;i++){
        ll md = (l+r)/2;
        ll ansL = get_ans(st,en,md);
        ll ansR = get_ans(st,en,md+1);
        // cout<<st<<" "<<en<<" "<<md<<"       "<<md+1<<"          "<<endl;
        // cout<<ansL<<"  "<<ansR<<endl;;
        // int c; cin>>c;
        if (ansL < ansR) r = md+1;
        else l = md;
    }
    int idx = l;
    ll ans1 = abs(get_sum(st,idx)-get_sum(idx+1,en));
    idx++;
    ll ans2 = abs(get_sum(st,idx)-get_sum(idx+1,en));
    if(ans1>ans2)return {get_sum(st,idx), get_sum(idx+1,en)};
    idx--;
    return {get_sum(st,idx), get_sum(idx+1,en)};
}
int main(){
    int n;
    ll L;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        v.pb(a[i]);
    }
    cum[0] = v[0];
    n = v.size();
    for(int i=1;i<n;i++)cum[i] = cum[i-1] + v[i];
    ll amid = 1e18;
    for (int i=0;i<n-1;i++){
        ii lf = get(0,i);
        ii rt = get(i+1,n-1);

        vector<ll> vv;
        vv.push_back(lf.fi);
        vv.push_back(lf.se);
        vv.push_back(rt.fi);
        vv.push_back(rt.se);
        // 3 1 1 3 2 2 3 3
        // cout<<"At "<<i<<": ";
        // for (auto nx:vv) cout<<nx<<" ";
        // cout<<endl;
        sort(vv.begin(),vv.end());
        amid = min(amid,vv[3]-vv[0]);
    }
    cout<<amid<<endl;
}
