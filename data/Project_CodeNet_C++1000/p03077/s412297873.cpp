#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}


int main(){
    ll N; cin >> N;
    vector<ll> cnt(5);
    for(auto &x : cnt) cin >> x;

    vector<ll> a(5);
    ll ans=0, mx=0;
    for(int i=0; i<5; i++){
        if(i == 0){
            a[i]=(N+cnt[i]-1)/cnt[i];
            ans+=max(a[i], 1LL);
        } 
        else{
            a[i]=(N+cnt[i]-1)/cnt[i];
            if(a[i] <= mx) ans+=1;
            else ans+=a[i]-mx+1;
        }
        chmax(mx, a[i]);
    }
    cout << ans << endl;
    return 0;
}