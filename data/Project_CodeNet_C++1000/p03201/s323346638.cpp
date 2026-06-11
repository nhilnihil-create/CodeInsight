#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    set<ll> s;
    map<ll,ll> m;
    rep(i,N){
        cin >> A[i];
        s.insert(A[i]);
        m[A[i]]++;
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    ll ans=0;
    rep(i,N){
        if (m[A[i]]>0){
            m[A[i]]--;
            if (m[A[i]]==0){
                s.erase(A[i]);
            }
            ll j=1;
            while(1){
                if ((1<<j)>A[i]){
                    break;
                }
                j++;
            }
            ll k=(1<<j)-A[i];
            if (s.count(k)){
                ans++;
                m[k]--;
                if (m[k]==0){
                    s.erase(k);
                }
            }
        }
    }
    cout << ans << endl;
}