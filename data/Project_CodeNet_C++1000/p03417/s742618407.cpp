#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    ll n,m;
    cin >> n >> m;
    if(n==1&&m==1){
        cout << 1 << endl;
        return 0;
    }
    if(n==1||m==1){
        if(n==1)swap(n,m);
        cout << n-2 << endl;
        return 0;
    }
    // 以下n,m>=2;
    cout << (n-2)*(m-2) << endl;
    return 0;
}