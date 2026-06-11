#include<bits/stdc++.h>

using namespace std;
using ll = long long;


ll cur;

class Union_Find{
private:
    std::vector<long long> data; //data[i] : 頂点iの親
public:
    Union_Find(ll n){
        data.resize(n,-1);
    }
    //頂点iの親を返す
    ll root(ll i){
        if(data[i] < 0)return i;
        else return data[i] = root(data[i]);
    }
    //連結
    void unit(ll i,ll j){
        i = root(i);j = root(j);
        if(i != j){
            data[i] += data[j];
            data[j] = i;
        }
    }

    //頂点iの属する集合の頂点数
    ll size(ll i){
        i = root(i);
        return -data[i];
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    Union_Find uni(n);
    vector<ll> a(m), b(m);
    for(ll i = 0; i < m; i++){
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
    }
    cur = (ll)(n - 1) * n / 2;
    vector<ll> ans(m);

    for(ll i = 0; i < m; i++) {
        ll x = a.back(), y = b.back();
        a.pop_back(), b.pop_back();
        ans[m - i - 1] = cur;
        if(uni.root(x) == uni.root(y))continue;
        cur -= (uni.size(y) * uni.size(x));
        uni.unit(x, y);
    }
    for(auto i : ans)cout << i << endl;
}