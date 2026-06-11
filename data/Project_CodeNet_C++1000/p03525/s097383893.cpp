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
    sort(d.begin(),d.end());
    vector<int> v(24);
    rep(i,n){
        if(d[i] == 0){
            cout << 0 << endl;
            return 0;
        }
        if(i&1) v[d[i]]++;
        else v[24-d[i]]++;
    }
    rep(i,24){
        if(v[i] >= 2){
            cout << 0 << endl;
            return 0;
        }
    }
    int before = 0;
    int ans = 24;
    rep(i,24){
        if(v[i]){
            ans = min(ans,i-before);
            before = i;
        }
    }
    ans = min(ans,24-before);
    cout << ans << endl;
} 


