#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};

int f(int a,int b){
    int res = 0;
    if(a >= b){
        while(a){
            a/=10;
            res++;
        }
    }else{
        while(b){
            while(b){
                b/=10;
                res++;
            }
        }
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    ll sum = 0;
    ll ans = 0;
    vector<ll> s;
    rep(i,n){
        if(a[i] < b[i]){
            ans++;
            sum += b[i] - a[i];
        }else if(a[i] > b[i]){
            s.push_back(a[i]-b[i]);
        }
    }
    if(sum == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(all(s),greater<ll>());
    rep(i,s.size()){
        sum -= s[i];
        ans++;
        if(sum <= 0){
            break;
        }
    }
    if(sum > 0){
        cout << -1 << endl;
        return 0;
    }else{
        cout << ans << endl;
    }


    cout << endl;
    return 0;
}
