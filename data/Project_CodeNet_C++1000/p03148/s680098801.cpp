#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array)
#define inin freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);


int main(){
 IOS
    ll n,k;
    cin>>n>>k;
    auto compare=[](pair<ll,ll> a, pair<ll,ll> b) {
        return a.second > b.second;
    };
    std::vector<pair<ll,ll>> v;
    ll aa,bb;
    fo(i,n){
        cin>>aa>>bb;
        v.pb({aa,bb});

    }
    sort(all(v),compare);
    vector<pair<ll,ll>> v2;
    vector<pair<ll,ll>> v3;
    map<ll,ll> mp;
    ll tmp=0;
    fo(i,k){
        tmp+=v[i].second;
        mp[v[i].first]++;
        v2.pb({v[i].first,v[i].second});

    }
    FOR(i,k,n-1){
         v3.pb({v[i].first,v[i].second});

    }
    tmp+=(sz(mp)*sz(mp));
    auto compare2=[](pair<ll,ll> a, pair<ll,ll> b) {
        return a.second < b.second;
    };
    sort(all(v2),compare2);
    sort(all(v3),compare);
    ll main_p=0;
    ll ans=tmp;
    //dbg(tmp);
    ll sec_p=0;
    while(true){
        if(!(main_p<sz(v2))||!(sec_p<sz(v3))) break;

        while(mp[v2[main_p].first]==1){
            main_p++;
        }

        if(!(main_p<sz(v2))||!(sec_p<sz(v3))) break;

        while((mp.count(v3[sec_p].first))) sec_p++;

        if(!(main_p<sz(v2))||!(sec_p<sz(v3))) break;

        tmp=tmp-v2[main_p].second+v3[sec_p].second;
        //dbg2(v2[main_p].first,v3[sec_p].first);
        tmp-=(sz(mp)*sz(mp));
        mp[v2[main_p].first]--;
        mp[v3[sec_p].first]++;
        main_p++;
        sec_p++;
        tmp+=(sz(mp)*sz(mp));
        ans=max(ans,tmp);



    }
    cout<<ans<<endl;




}