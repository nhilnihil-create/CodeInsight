#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int n; cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    if(n >= 24){
        cout << 0 << endl;
        return 0;
    }
    vector<int> cnt(25);
    if(n == 23){
        rep(i,n) cnt[d[i]]++;
        if(cnt[12] >= 2){
            cout << 0 << endl;
            return 0;
        }
        bool ok = false;
        rep(i,n){
            if(cnt[i] >= 3) ok = true;
        }
        cout << (ok?0:1) << endl;
        return 0;
    }
    int ans = 0;
    rep(i,1<<n){
        vector<int> v;
        rep(j,n){
            if(i>>j&1){
                v.push_back(d[j]);
            }
            else v.push_back(24-d[j]);
        }
        sort(v.begin(),v.end());
        int now = v[0];
        rep(i,n-1) now = min(now,v[i+1]-v[i]);
        now = min(now,24-v[(int)v.size()-1]);
        ans = max(ans,now);
    }
    cout << ans << endl;
} 


