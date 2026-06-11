#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
const ll MOD=1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    int pos=0,neg=0,p,n;
    rep (i,N){
        cin >> a[i];
        if (pos<a[i]){
            pos=a[i];
            p=i;
        }
        else if (a[i]<neg){
            neg=a[i];
            n=i;
        }
    }
    vector<Pii> ans;
    if (-neg<pos){
        rep(i,N){
            if (a[i]<0){
                ans.push_back(Pii(p+1,i+1));
            }
        }
        rep(i,N-1){
            ans.push_back(Pii(i+1,i+2));
        }
    }
    else {
        rep(i,N){
            if (a[i]>0){
                ans.push_back(Pii(n+1,i+1));
            }
        }
        rep(i,N-1){
            ans.push_back(Pii(N-i,N-i-1));
        }
    }
    cout << ans.size() << endl;
    rep(i,ans.size()){
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}