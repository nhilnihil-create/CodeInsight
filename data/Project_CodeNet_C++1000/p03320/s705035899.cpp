#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vec<ll> pow10(16,1);
    for(int i=1;i<=15;i++) pow10[i] = pow10[i-1]*10;
    vec<ll> ans;
    for(int i=1;i<10;i++) ans.push_back(i);
    ll now = 9;

    auto digit = [](ll x){
        int res = 0;
        while(x){
            res += x%10;
            x /= 10;
        }
        return res;
    };
    
    int K;
    cin >> K;
    while((int) ans.size()<K){
        vec<pair<double,ll>> A;
        for(int i=0;i<16;i++){
            ll val = now+pow10[i];
            A.emplace_back(1.0*val/digit(val),val);
        }
        ll val = 10*now+9;
        A.emplace_back(1.0*val/digit(val),val);
        sort(A.begin(),A.end());
        ans.push_back(A[0].second);
        now = A[0].second;
    }
    for(int i=0;i<K;i++) cout << ans[i] << "\n";   
}