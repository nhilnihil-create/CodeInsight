#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define int long long

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
signed main(){
    int n,X;
    cin >> n >> X;
    
    vector<ll> a(n);
    vector<ll> s(n+1);
    rep(i,n)cin >> a[i];
    ll sm = 0;
    for(int i=n-1;i>=0;i--){
        s[i]=a[i];
        sm += a[i];
        s[i] += s[i+1];
    }
    ll ans = (1LL<<60);
    
    for(int k=1;k<=n;k++){
        ll tmp = 5*sm+(n+k)*X;
        int c = n-k-1;
        int p = 0;
        while(c>=0){
            if(c-k+1 > 0){
                tmp += p*(s[c-k+1]-s[c+1]);
            }else{
                tmp += p*(s[0] - s[c+1]);
            }
            p += 2;
            c -= k;
            if(tmp > ans)break;
        }
        // cerr << k << " " << tmp << endl;
        chmin(ans,tmp); 
    }
    cout << ans << endl;
    return 0;
}