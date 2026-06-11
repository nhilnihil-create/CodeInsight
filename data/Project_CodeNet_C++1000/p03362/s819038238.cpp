// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

// 素数判定
// 計算量O(√n)
template<class T>
bool isPrime(T n){
    if(n < 2) return false;
    for(long long i = 2; i*i <= n; ++i) if(n % i == 0) return false;
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    ll k = 5;
    vector<ll> ans;
    ans.push_back(2);
    rep(i,n-1){
        while(!isPrime(2*k+1)) k += 5;
        ans.push_back(2*k+1);
        k += 5;
    }
    rep(i,n){
        cout << ans[i];
        if(i != n-1) cout << " ";
    }
    cout << "\n";
}